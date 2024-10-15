#include "bs-preset-chooser-page.h"

struct _BsPresetChooserPage
{
  ScNavigationPage parent_instance;
  AdwPreferencesGroup *preset_group;
};

G_DEFINE_FINAL_TYPE (BsPresetChooserPage, bs_preset_chooser_page, SC_TYPE_NAVIGATION_PAGE)

static void
bs_preset_chooser_page_class_init (BsPresetChooserPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatstep/bs-preset-chooser-page.ui");
  gtk_widget_class_bind_template_child (widget_class, BsPresetChooserPage, preset_group);
}

static void
bs_preset_chooser_page_init (BsPresetChooserPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}

GtkWidget *
bs_preset_chooser_page_new (int presets_num, preset_chooser_func activate_cb, BsPresetPage* preset_page)
{
  GtkWidget *page = g_object_new (BS_TYPE_PRESET_CHOOSER_PAGE, NULL);
  BsPresetChooserPage *pc_page = BS_PRESET_CHOOSER_PAGE (page);

  for(int i = 0; i < presets_num; ++i)
  {
    GtkWidget* row = bs_preset_chooser_row_new (i + 1);
    g_signal_connect_swapped (row, "activated", G_CALLBACK (activate_cb), preset_page);
    adw_preferences_group_add (pc_page->preset_group, row);
  }

  return page;
}
