#include "sc-color-row.h"

G_DEFINE_TYPE (ScColorRow, sc_color_row, ADW_TYPE_COMBO_ROW)

gchararray
cv_to_markup_color (GObject *object, ScControlValue* value)
{
  GString *markup;

  /* TODO: why can it be NULL? */
  if (!value)
    return NULL;

  g_return_val_if_fail (SC_IS_CONTROL_VALUE (value), NULL);

  markup = g_string_new("<span bgcolor=\"::color\">     </span>");
  g_string_replace(markup, "::color", sc_control_value_get_name (value), 1);
  return g_string_free_and_steal(markup);
}

static void
sc_color_row_class_init (ScColorRowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/sc-color-row.ui");
}

static void
sc_color_row_init (ScColorRow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
