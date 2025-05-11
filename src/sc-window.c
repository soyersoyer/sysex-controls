#include <alsa/asoundlib.h>

#include "config.h"

#include "sc-controller-row.h"
#include "sc-control-value.h"
#include "sc-midi.h"
#include "sc-window.h"

#include "beatstep/bs-book.h"
#include "beatsteppro/bsp-book.h"
#include "drumbrute/db-book.h"
#include "drumbruteimpact/dbi-book.h"
#include "keylab2/kl2-book.h"
#include "keylab3/kl3-book.h"
#include "keylab/kl-book.h"
#include "keylab88/kl88-book.h"
#include "keylabes/kles-book.h"
#include "keylabes3/kles3-book.h"
#include "keystep32/ks32-book.h"
#include "keystep37/ks37-book.h"
#include "keysteppro/ksp-book.h"
#include "microlab/microlab-book.h"
#include "minibrute2/mb2-book.h"
#include "minibrute2s/mb2s-book.h"
#include "minilab/ml-book.h"
#include "minilab2/ml2-book.h"
#include "minilab3/ml3-book.h"
#include "mpkmini/amm-book.h"
#include "mpkmini2/amm2-book.h"
#include "mpkmini3/amm3-book.h"
#include "sparkle/sple-book.h"
#include "thelaboratory/tl-book.h"

typedef const struct {
  const char *midi_name;
  const char *short_name;
  GType (*type)(void);
  bool use_dummy;
} controller_t;

static controller_t controllers[] = {
  {BS_MIDI_NAME, BS_SHORT_NAME, bs_book_get_type},
  {BSP_MIDI_NAME, BSP_SHORT_NAME, bsp_book_get_type},
  {DB_MIDI_NAME, DB_SHORT_NAME, db_book_get_type},
  {DBI_MIDI_NAME, DBI_SHORT_NAME, dbi_book_get_type},
  {KL2_49_MIDI_NAME, KL2_49_SHORT_NAME, kl2_book_get_type},
  {KL2_61_MIDI_NAME, KL2_61_SHORT_NAME, kl2_book_get_type},
  {KL2_88_MIDI_NAME, KL2_88_SHORT_NAME, kl2_book_get_type},
  {KL3_49_MIDI_NAME, KL3_49_SHORT_NAME, kl3_book_get_type},
  {KL3_61_MIDI_NAME, KL3_61_SHORT_NAME, kl3_book_get_type},
  {KL3_88_MIDI_NAME, KL3_88_SHORT_NAME, kl3_book_get_type},
  {KL49_MIDI_NAME, KL49_SHORT_NAME, kl_book_get_type},
  {KL61_MIDI_NAME, KL61_SHORT_NAME, kl_book_get_type},
  {KL88_MIDI_NAME, KL88_SHORT_NAME, kl88_book_get_type},
  {KLES_49_MIDI_NAME, KLES_49_SHORT_NAME, kles_book_get_type},
  {KLES_61_MIDI_NAME, KLES_61_SHORT_NAME, kles_book_get_type},
  {KLES_88_MIDI_NAME, KLES_88_SHORT_NAME, kles_book_get_type},
  {KLES3_49_MIDI_NAME, KLES3_49_SHORT_NAME, kles3_book_get_type},
  {KLES3_61_MIDI_NAME, KLES3_61_SHORT_NAME, kles3_book_get_type},
  {KLES3_88_MIDI_NAME, KLES3_88_SHORT_NAME, kles3_book_get_type},
  {KS32_MIDI_NAME, KS32_SHORT_NAME, ks32_book_get_type},
  {KS37_MIDI_NAME, KS37_SHORT_NAME, ks37_book_get_type},
  {KSP_MIDI_NAME, KSP_SHORT_NAME, ksp_book_get_type},
  {MICROLAB_MIDI_NAME, MICROLAB_SHORT_NAME, microlab_book_get_type},
  {MB2_MIDI_NAME, MB2_SHORT_NAME, mb2_book_get_type},
  {MB2S_MIDI_NAME, MB2S_SHORT_NAME, mb2s_book_get_type},
  {ML_MIDI_NAME, ML_SHORT_NAME, ml_book_get_type},
  {ML2_MIDI_NAME, ML2_SHORT_NAME, ml2_book_get_type},
  {ML3_MIDI_NAME, ML3_SHORT_NAME, ml3_book_get_type},
  {AMM_MIDI_NAME, AMM_SHORT_NAME, amm_book_get_type},
  {AMM2_MIDI_NAME, AMM2_SHORT_NAME, amm2_book_get_type},
  {AMM2_MIDI_NAME_2, AMM2_SHORT_NAME, amm2_book_get_type},
  {AMM3_MIDI_NAME, AMM3_SHORT_NAME, amm3_book_get_type},
  {SPLE_MIDI_NAME, SPLE_SHORT_NAME, sple_book_get_type},
  {TL_MIDI_NAME, TL_SHORT_NAME, tl_book_get_type},
};

struct _ScWindow
{
  AdwApplicationWindow  parent_instance;

  snd_seq_t *seq;

  GListStore *page_list;

  /* Template widgets */
  AdwToastOverlay *toast_overlay;
  GtkListBox *sidebar;
  AdwClamp *controller_list_clamp;
  AdwNavigationPage  *setting_page;
  AdwNavigationView  *navigation_view;
  AdwNavigationSplitView *split_view;
  ScBook *book;
};

G_DEFINE_FINAL_TYPE (ScWindow, sc_window, ADW_TYPE_APPLICATION_WINDOW)

static void
on_sidebar_row_activated_cb (GtkListBox* list, GtkListBoxRow *row, ScWindow *self)
{
  int idx = gtk_list_box_row_get_index (row);
  AdwNavigationPage *page = ADW_NAVIGATION_PAGE (g_list_model_get_item (G_LIST_MODEL (self->page_list), idx));
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_parent (GTK_WIDGET (page)));
  adw_navigation_view_replace (view, (AdwNavigationPage *[]){page}, 1);
  adw_navigation_split_view_set_show_content (self->split_view, TRUE);
}

static GtkWidget *
sidebar_row_new (AdwNavigationPage *page, AdwNavigationView *self)
{
  GtkListBoxRow *row = GTK_LIST_BOX_ROW (gtk_list_box_row_new ());
  GtkLabel *label = GTK_LABEL (gtk_label_new (adw_navigation_page_get_title (ADW_NAVIGATION_PAGE (page))));
  gtk_widget_set_margin_top (GTK_WIDGET (label), 6);
  gtk_widget_set_margin_bottom (GTK_WIDGET (label), 6);
  gtk_widget_set_margin_start (GTK_WIDGET (label), 6);
  gtk_widget_set_margin_end (GTK_WIDGET (label), 6);
  gtk_widget_set_halign (GTK_WIDGET (label), GTK_ALIGN_START);
  gtk_list_box_row_set_child (row, GTK_WIDGET (label));
  return GTK_WIDGET (row);
}

static void
sc_window_set_book (ScWindow *self, ScBook *book)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (adw_navigation_page_get_child (ADW_NAVIGATION_PAGE (book)));
  adw_navigation_split_view_set_content(self->split_view, ADW_NAVIGATION_PAGE (book));
  self->book = book;

  g_list_store_remove_all (self->page_list);

  for (GtkWidget *page = gtk_widget_get_first_child (GTK_WIDGET (view));
       page; page = gtk_widget_get_next_sibling (page))
    if (ADW_IS_NAVIGATION_PAGE (page))
      g_list_store_append (self->page_list, page);
}

static void
sc_window_midi_connect (ScWindow *self, ScControllerRow *row)
{
  ScBook *book;
  controller_t *controller = NULL;
  sc_midi_info_t *ci = sc_controller_row_get_info (row);

  for (int i = 0; i < sizeof controllers / sizeof controllers[0]; ++i) {
    if (strcmp(controllers[i].midi_name, ci->client_name) == 0)
    {
      controller = &controllers[i];
      break;
    }
  }

  if (controller == NULL) {
    sc_io_problem (self, "%s is not supported yet. Please open an issue.", ci->client_name);
    return;
  }

  if (sc_midi_connect (self->seq, ci->addr) < 0)
  {
    sc_io_problem (self, "Failed to connect %d:%d", ci->addr.client, ci->addr.port);
    return;
  }

  adw_navigation_page_set_title (self->setting_page, controller->short_name);

  book = SC_BOOK (g_object_new (controller->type (), NULL));

  sc_book_set_seq (book, self->seq, ci->addr);

  if (controller->use_dummy)
    sc_book_use_dummy (book);

  sc_window_set_book (self, book);

  adw_navigation_view_replace_with_tags (self->navigation_view, (const char * const[]){"setting", "load"}, 2);
  g_idle_add (G_SOURCE_FUNC (sc_book_load), self->book);
}

static void
controller_select_cb (ScWindow *self, AdwActionRow *row)
{
  sc_window_midi_connect (self, SC_CONTROLLER_ROW (row));
}

/*
 * The back button of AdwNavigationSplitView doesn't work well when the view
 * is inside AdwNavigationSplitView,
 *
 * add a separated back button
 * never push list and setting to the navigation stack together
 *
 *  TODO: check later or fix in libadwaita
 */

static void
show_list_click_cb (ScWindow *self, GtkButton *btn)
{
  adw_navigation_view_replace_with_tags (self->navigation_view, (const char * const[]){"list"}, 1);
}

static void
sc_midi_init (ScWindow *self)
{
  sc_midi_info_t cc[10];
  GtkWidget *controller_list;
  int fc;

  if (self->seq)
    sc_midi_close (&self->seq);

  if (sc_midi_open (&self->seq) < 0)
  {
    g_warning ("Failed to open midi");
    return;
  }

  fc = sc_midi_get_controllers (self->seq, cc, 10);

  g_debug ("found %d controller:", fc);

  controller_list = adw_preferences_group_new ();
  adw_preferences_group_set_title (ADW_PREFERENCES_GROUP (controller_list), "Controllers");

  for (int i = 0; i < fc; ++i)
  {
    GtkWidget *row = sc_controller_row_new (&cc[i]);
    g_signal_connect_swapped (G_OBJECT (row), "activated", G_CALLBACK (controller_select_cb), self);
    adw_preferences_group_add (ADW_PREFERENCES_GROUP (controller_list), row);

    g_debug ("%s %d:%d", cc[i].port_name, cc[i].addr.client, cc[i].addr.port);
  }

  adw_clamp_set_child (self->controller_list_clamp, controller_list);

  if (fc == 0)
    adw_navigation_view_replace_with_tags (self->navigation_view, (const char * const[]){"search"}, 1);
  else
    adw_navigation_view_replace_with_tags (self->navigation_view, (const char * const[]){"list"}, 1);
}

static void
refresh_button_click_cb (ScWindow *self)
{
  sc_midi_init (SC_WINDOW (self));
}

static void
list_shown_cb (ScWindow *self)
{
  if (self->book)
    sc_midi_disconnect (self->seq, sc_book_get_addr (self->book));
}

void
sc_window_pop_page (ScWindow *self)
{
  adw_navigation_view_pop (self->navigation_view);
}

static void
sc_window_class_init (ScWindowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/sc-window.ui");
  gtk_widget_class_bind_template_child (widget_class, ScWindow, toast_overlay);
  gtk_widget_class_bind_template_child (widget_class, ScWindow, sidebar);
  gtk_widget_class_bind_template_child (widget_class, ScWindow, controller_list_clamp);
  gtk_widget_class_bind_template_child (widget_class, ScWindow, setting_page);
  gtk_widget_class_bind_template_child (widget_class, ScWindow, navigation_view);
  gtk_widget_class_bind_template_child (widget_class, ScWindow, split_view);
  gtk_widget_class_bind_template_callback (widget_class, refresh_button_click_cb);
  gtk_widget_class_bind_template_callback (widget_class, controller_select_cb);
  gtk_widget_class_bind_template_callback (widget_class, show_list_click_cb);
  gtk_widget_class_bind_template_callback (widget_class, list_shown_cb);
}

static void
sc_window_init (ScWindow *self)
{
  g_type_ensure (SC_TYPE_CONTROLLER_ROW);

  gtk_widget_init_template (GTK_WIDGET (self));

  self->page_list = g_list_store_new(ADW_TYPE_NAVIGATION_PAGE);
  gtk_list_box_bind_model (self->sidebar, G_LIST_MODEL (self->page_list), (GtkListBoxCreateWidgetFunc)sidebar_row_new, self->sidebar, NULL);
  g_signal_connect (self->sidebar, "row-activated", G_CALLBACK (on_sidebar_row_activated_cb), self);

  sc_midi_init (self);
}

void
__attribute__ ((format (gnu_printf, 2, 3)))
sc_io_problem (ScWindow *self, const char *format, ...)
{
  char message[128];
  AdwToast *toast;
  va_list args;

  va_start(args, format);
  vsnprintf(message, 128,  format, args);
  va_end (args);

  g_warning ("%s", message);

  toast = adw_toast_new (message);
  adw_toast_set_timeout (toast, 2);
  adw_toast_set_priority (toast, ADW_TOAST_PRIORITY_HIGH);
  adw_toast_overlay_add_toast (self->toast_overlay, toast);
  // TODO: better error handling
  sc_midi_init (self);
}
