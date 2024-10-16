#include "ar-preset-chooser-row.h"

struct _ArPresetChooserRow
{
  AdwActionRow parent_instance;
  uint8_t preset_id;
};

G_DEFINE_FINAL_TYPE (ArPresetChooserRow, ar_preset_chooser_row, ADW_TYPE_ACTION_ROW)

uint8_t
ar_preset_chooser_row_get_preset_id (ArPresetChooserRow *self)
{
  return self->preset_id;
}

static void
ar_preset_chooser_row_class_init (ArPresetChooserRowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/ar-preset-chooser-row.ui");
}

static void
ar_preset_chooser_row_init (ArPresetChooserRow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}

GtkWidget *
ar_preset_chooser_row_new (uint8_t preset_id)
{
  GtkWidget *row = g_object_new (AR_TYPE_PRESET_CHOOSER_ROW, NULL);
  char preset_name[11];

  snprintf(preset_name, 11,  "Preset %d", preset_id);
  AR_PRESET_CHOOSER_ROW (row)->preset_id = preset_id;

  adw_preferences_row_set_title (ADW_PREFERENCES_ROW (row), preset_name);

  return row;
}
