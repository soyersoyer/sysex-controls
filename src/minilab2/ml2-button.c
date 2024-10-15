#include "ml2-button.h"

struct _Ml2Button
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml2Button, ml2_button, SC_TYPE_PREFERENCES_GROUP)

static void
ml2_button_class_init (Ml2ButtonClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab2/ml2-button.ui");
}

static void
ml2_button_init (Ml2Button *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
