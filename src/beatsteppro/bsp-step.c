#include "bsp-step.h"

struct _BspStep
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (BspStep, bsp_step, SC_TYPE_PREFERENCES_GROUP)

static void
bsp_step_class_init (BspStepClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatsteppro/bsp-step.ui");
}

static void
bsp_step_init (BspStep *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
