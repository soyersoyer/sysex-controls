#include "ar-preset-page.h"

#include "sc-arturia-book.h"
#include "ar-preset-chooser-page.h"
#include "ar-preset-chooser-row.h"
#include "sc-window.h"

struct _ArPresetPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (ArPresetPage, ar_preset_page, SC_TYPE_NAVIGATION_PAGE)

static void on_selected_recall (ArPresetPage *self, ArPresetChooserRow *row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  ScArturiaBook *book = SC_ARTURIA_BOOK (gtk_widget_get_ancestor (GTK_WIDGET (self), SC_TYPE_ARTURIA_BOOK));
  ScWindow *window = SC_WINDOW (gtk_widget_get_ancestor (GTK_WIDGET (self), SC_TYPE_WINDOW));
  uint8_t preset_id = ar_preset_chooser_row_get_preset_id (row);
  g_debug ("on_selected_recall selected preset_id: %d", preset_id);
  if (sc_arturia_book_recall_preset (book, preset_id) == 0)
  {
    adw_navigation_view_pop (view);
    sc_window_load_page (window, "list");
    return;
  }
  else
  {
    sc_io_problem (window, "Preset recall failed");
    return;
  }
}

static void on_selected_store (ArPresetPage *self, ArPresetChooserRow *row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  ScArturiaBook *book = SC_ARTURIA_BOOK (gtk_widget_get_ancestor (GTK_WIDGET (self), SC_TYPE_ARTURIA_BOOK));
  ScWindow *window = SC_WINDOW (gtk_widget_get_ancestor (GTK_WIDGET (self), SC_TYPE_WINDOW));
  uint8_t preset_id = ar_preset_chooser_row_get_preset_id (row);
  g_debug ("on_selected_store selected preset_id: %d", preset_id);
  if (sc_arturia_book_store_preset (book, preset_id) != 0)
  {
    sc_io_problem (window, "Preset store failed");
    return;
  }
  adw_navigation_view_pop (view);
}

void on_recall_activated (ArPresetPage *self, AdwActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *preset_list = ADW_NAVIGATION_PAGE (ar_preset_chooser_page_new (16, on_selected_recall, self));
  adw_navigation_view_push (view, preset_list);
}

void on_store_activated (ArPresetPage *self, AdwActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *preset_list = ADW_NAVIGATION_PAGE (ar_preset_chooser_page_new (16, on_selected_store, self));
  adw_navigation_view_push (view, preset_list);
}

static void
ar_preset_page_class_init (ArPresetPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/ar-preset-page.ui");
}

static void
ar_preset_page_init (ArPresetPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
