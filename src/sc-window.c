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
#include "keylab25/kl25-book.h"
#include "keylab88/kl88-book.h"
#include "keylabes/kles-book.h"
#include "keylabes3/kles3-book.h"
#include "keystep32/ks32-book.h"
#include "keystep37/ks37-book.h"
#include "keysteppro/ksp-book.h"
#include "microlab/microlab-book.h"
#include "microlab3/microlab3-book.h"
#include "minibrute2/mb2-book.h"
#include "minibrute2s/mb2s-book.h"
#include "minilab/ml-book.h"
#include "minilab2/ml2-book.h"
#include "minilab3/ml3-book.h"
#include "mpkmini/amm-book.h"
#include "mpkmini2/amm2-book.h"
#include "mpkmini3/amm3-book.h"
#include "nanokey2/nk2-book.h"
#include "nanokontrol2/nkl2-book.h"
#include "sparkle/sple-book.h"
#include "thelaboratory/tl-book.h"

typedef const struct {
  const char *client_name;
  const char *short_name;
  GType (*type)(void);
  bool use_dummy;
} controller_t;

static controller_t controllers[] = {
  {"Arturia BeatStep", "BeatStep", bs_book_get_type},
  {"Arturia BeatStep Pro", "BSP", bsp_book_get_type},
  {"Arturia DrumBrute", "DrumBrute", db_book_get_type},
  {"Arturia DrumBrute Impact", "DB Impact", dbi_book_get_type},
  {"KeyLab mkII 49", "KL mkII 49", kl2_book_get_type},
  {"KeyLab mkII 61", "KL mkII 61", kl2_book_get_type},
  {"KeyLab mkII 88", "KL mkII 88", kl2_book_get_type},
  {"KeyLab 49 mk3", "KeyLab 49 mk3", kl3_book_get_type},
  {"KeyLab 61 mk3", "KeyLab 61 mk3", kl3_book_get_type},
  {"KeyLab 88 mk3", "KeyLab 88 mk3", kl3_book_get_type},
  {"KeyLab 25", "KeyLab 25", kl25_book_get_type},
  {"KeyLab 49", "KeyLab 49", kl_book_get_type},
  {"KeyLab 61", "KeyLab 61", kl_book_get_type},
  {"KeyLab 88", "KeyLab 88", kl88_book_get_type},
  {"Arturia KeyLab Essential 49", "KeyLab ES 49", kles_book_get_type},
  {"Arturia KeyLab Essential 61", "KeyLab ES 61", kles_book_get_type},
  {"Arturia KeyLab Essential 88", "KeyLab ES 88", kles_book_get_type},
  {"KL Essential 49 mk3", "KeyLab ES 49 mk3", kles3_book_get_type},
  {"KL Essential 61 mk3", "KeyLab ES 61 mk3", kles3_book_get_type},
  {"KL Essential 88 mk3", "KeyLab ES 88 mk3", kles3_book_get_type},
  {"Arturia KeyStep 32", "KeyStep 32", ks32_book_get_type},
  {"Arturia KeyStep 37", "KeyStep 37", ks37_book_get_type},
  {"KeyStep Pro", "KeyStep Pro", ksp_book_get_type},
  {"Arturia MicroLab", "MicroLab", microlab_book_get_type},
  {"MicroLab mk3", "MicroLab3", microlab3_book_get_type},
  {"Arturia MiniBrute 2", "MiniBrute 2", mb2_book_get_type},
  {"Arturia MiniBrute 2S", "MiniBrute 2S", mb2s_book_get_type},
  {"Arturia MINILAB", "MiniLab", ml_book_get_type},
  {"Arturia MiniLab mkII", "ML mkII", ml2_book_get_type},
  {"Minilab3", "MiniLab 3", ml3_book_get_type},
  {"nanoKEY2", "nanoKEY2", nk2_book_get_type},
  {"nanoKONTROL2", "nanoKONTROL2", nkl2_book_get_type},
  {"MPK mini", "MPK mini", amm_book_get_type},
  {"MPKmini2", "MPK mini 2", amm2_book_get_type},
  {"MPK Mini Mk II", "MPK mini 2", amm2_book_get_type},
  {"MPK mini 3", "MPK mini 3", amm3_book_get_type},
  {"SparkLE", "SparkLE", sple_book_get_type},
  {"The Laboratory", "Laboratory", tl_book_get_type},
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

static const controller_t *
find_controller (const char* client_name)
{
  for (int i = 0; i < sizeof controllers / sizeof controllers[0]; ++i)
    if (strcmp (controllers[i].client_name, client_name) == 0)
      return &controllers[i];
  return NULL;
}

static void
sc_window_midi_connect (ScWindow *self, ScControllerRow *row)
{
  ScBook *book;
  sc_midi_info_t *ci = sc_controller_row_get_info (row);
  controller_t *controller = find_controller (ci->client_name);

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

static bool
filter_supported (sc_midi_info_t *c)
{
  return find_controller (c->client_name);
}

static void
sc_midi_init (ScWindow *self)
{
  const uint8_t list_size = 64;
  sc_midi_info_t controller_list[list_size];
  GtkWidget *controller_group;
  int fc;

  if (self->seq)
    sc_midi_close (&self->seq);

  if (sc_midi_open (&self->seq) < 0)
  {
    g_warning ("Failed to open midi");
    return;
  }

  fc = sc_midi_get_controllers (self->seq, controller_list, list_size, filter_supported);

  g_debug ("found %d controllers:", fc);

  controller_group = adw_preferences_group_new ();
  adw_preferences_group_set_title (ADW_PREFERENCES_GROUP (controller_group), "Controllers");

  for (int i = 0; i < fc; ++i)
  {
    sc_midi_info_t *c = &controller_list[i];
    GtkWidget *row = sc_controller_row_new (c);
    g_signal_connect_swapped (G_OBJECT (row), "activated", G_CALLBACK (controller_select_cb), self);
    adw_preferences_group_add (ADW_PREFERENCES_GROUP (controller_group), row);

    g_debug ("%s %d:%d", c->port_name, c->addr.client, c->addr.port);
  }

  adw_clamp_set_child (self->controller_list_clamp, controller_group);

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
