#include "sc-controller-row.h"

struct _ScControllerRow
{
  AdwActionRow parent_instance;
  sc_midi_info_t info;
};

G_DEFINE_FINAL_TYPE (ScControllerRow, sc_controller_row, ADW_TYPE_ACTION_ROW)

static void
sc_controller_row_class_init (ScControllerRowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/sc-controller-row.ui");
}

static void
sc_controller_row_init (ScControllerRow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}

GtkWidget * sc_controller_row_new (sc_midi_info_t *info)
{
  char sub[32];
  GtkWidget *row = g_object_new (SC_TYPE_CONTROLLER_ROW, NULL);
  ScControllerRow *self = SC_CONTROLLER_ROW (row);

  self->info = *info;

  adw_preferences_row_set_title (ADW_PREFERENCES_ROW (row), info->port_name);

  snprintf(sub, 32, "Port %d:%d", info->addr.client, info->addr.port);
  adw_action_row_set_subtitle (ADW_ACTION_ROW (row), sub);

  return row;
}

sc_midi_info_t * sc_controller_row_get_info (ScControllerRow *self)
{
  return &self->info;
}
