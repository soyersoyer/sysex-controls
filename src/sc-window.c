#include <alsa/asoundlib.h>

#include "config.h"

#include "sc-controller-row.h"
#include "sc-control-value.h"
#include "sc-midi.h"
#include "sc-util.h"
#include "sc-window.h"

#include "keystep37/ks37-book.h"
#include "minilab2/ml2-book.h"
#include "minilab3/ml3-book.h"
#include "beatstep/bs-book.h"

typedef GtkWidget * (*book_init_func)(snd_seq_t*, snd_seq_addr_t*);

typedef const struct {
  const char *midi_name;
  const char *short_name;
  book_init_func init;
} controller_t;

static controller_t controllers[] = {
  {KS37_MIDI_NAME, KS37_SHORT_NAME, ks37_book_new},
  {ML2_MIDI_NAME, ML2_SHORT_NAME, ml2_book_new},
  {ML3_MIDI_NAME, ML3_SHORT_NAME, ml3_book_new},
  {BS_MIDI_NAME, BS_SHORT_NAME, bs_book_new},
};

struct _ScWindow
{
  AdwApplicationWindow  parent_instance;

  snd_seq_t *seq;

  /* Template widgets */
  AdwToastOverlay *toast_overlay;
  GtkStackSidebar *sidebar;
  AdwClamp *controller_list_clamp;
  AdwNavigationPage  *setting_page;
  AdwNavigationPage  *content_page;
  AdwToolbarView *content_view;
  AdwNavigationView  *navigation_view;
  AdwNavigationSplitView *split_view;
  ScArturiaBook *book;
};

G_DEFINE_FINAL_TYPE (ScWindow, sc_window, ADW_TYPE_APPLICATION_WINDOW)

void
__attribute__ ((format (gnu_printf, 2, 3)))
sc_io_problem (ScWindow *self, const char *format, ...)
{
  char message[128];
  va_list args;

  va_start(args, format);
  vsnprintf(message, 128,  format, args);
  va_end (args);

  g_warning ("%s", message);

  adw_toast_overlay_add_toast (self->toast_overlay, adw_toast_new (message));
  adw_navigation_view_replace_with_tags(self->navigation_view, (const char * const[]){"list"}, 1);
}


static int
sc_create_load_task (ScArturiaBook *book)
{
  GTask *task = g_task_new (book, NULL, sc_arturia_book_load_task_finish, NULL);
  g_task_run_in_thread (task, sc_arturia_book_load_task);
  g_object_unref (task);
  return false;
}

static void
notify_visible_child_cb (GtkStack* stack, GParamSpec *pspec, ScWindow *self)
{
  GtkWidget *child = gtk_stack_get_visible_child (stack);
  GtkStackPage *page = gtk_stack_get_page (stack, child);

  adw_navigation_page_set_title (self->content_page, gtk_stack_page_get_title (page));
  adw_navigation_split_view_set_show_content (self->split_view, TRUE);
}


static void
sc_window_set_book (ScWindow *self, ScArturiaBook *book)
{
  GtkStack *stack = GTK_STACK (adw_bin_get_child(ADW_BIN (book)));
  self->book = book;
  adw_toolbar_view_set_content(self->content_view, GTK_WIDGET (book));
  gtk_stack_sidebar_set_stack (self->sidebar, stack);

  g_signal_connect (stack, "notify::visible-child", G_CALLBACK (notify_visible_child_cb), self);

  notify_visible_child_cb (stack, NULL, self);
}

static void
sc_window_midi_connect (ScWindow *self, ScControllerRow *row)
{
  controller_t *controller = NULL;
  sc_midi_info_t *ci = sc_controller_row_get_info (row);

  for (int i = 0; i < ARRAY_SIZE(controllers); ++i) {
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
  sc_window_set_book (self, SC_ARTURIA_BOOK (controller->init (self->seq, &ci->addr)));

  adw_navigation_view_replace_with_tags (self->navigation_view, (const char * const[]){"load"}, 1);
  g_idle_add (G_SOURCE_FUNC (sc_create_load_task), self->book);
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
setting_hidden_cb (ScWindow *self)
{
  sc_midi_disconnect (self->seq, sc_arturia_book_get_addr (self->book));
}

void
sc_window_load_page (ScWindow *self, const char *name)
{
  adw_navigation_view_replace_with_tags (self->navigation_view, (const char * const[]){name}, 1);
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
  gtk_widget_class_bind_template_child (widget_class, ScWindow, content_page);
  gtk_widget_class_bind_template_child (widget_class, ScWindow, content_view);
  gtk_widget_class_bind_template_child (widget_class, ScWindow, navigation_view);
  gtk_widget_class_bind_template_child (widget_class, ScWindow, split_view);
  gtk_widget_class_bind_template_callback (widget_class, refresh_button_click_cb);
  gtk_widget_class_bind_template_callback (widget_class, controller_select_cb);
  gtk_widget_class_bind_template_callback (widget_class, show_list_click_cb);
  gtk_widget_class_bind_template_callback (widget_class, setting_hidden_cb);
}

static void
sc_window_init (ScWindow *self)
{
  g_type_ensure (SC_TYPE_CONTROLLER_ROW);

  gtk_widget_init_template (GTK_WIDGET (self));

  // remove the unecessary right border
  gtk_widget_remove_css_class (GTK_WIDGET (self->sidebar), "sidebar");

  sc_midi_init (self);
}
