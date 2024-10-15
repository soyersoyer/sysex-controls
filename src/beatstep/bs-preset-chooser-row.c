#include "bs-preset-chooser-row.h"

struct _BsPresetChooserRow
{
  AdwActionRow parent_instance;
  uint8_t preset_id;
};

G_DEFINE_FINAL_TYPE (BsPresetChooserRow, bs_preset_chooser_row, ADW_TYPE_ACTION_ROW)

uint8_t
bs_preset_chooser_row_get_preset_id (BsPresetChooserRow *self)
{
  return self->preset_id;
}

static void
bs_preset_chooser_row_class_init (BsPresetChooserRowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatstep/bs-preset-chooser-row.ui");
}

static void
bs_preset_chooser_row_init (BsPresetChooserRow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}

GtkWidget *
bs_preset_chooser_row_new (uint8_t preset_id)
{
  GtkWidget *row = g_object_new (BS_TYPE_PRESET_CHOOSER_ROW, NULL);
  char preset_name[11];

  snprintf(preset_name, 11,  "Preset %d", preset_id);
  BS_PRESET_CHOOSER_ROW (row)->preset_id = preset_id;

  adw_preferences_row_set_title (ADW_PREFERENCES_ROW (row), preset_name);

  return row;
}
