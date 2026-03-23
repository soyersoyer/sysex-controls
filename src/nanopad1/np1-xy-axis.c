#include "np1-xy-axis.h"

struct _Np1XyAxis
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Np1XyAxis, np1_xy_axis, SC_TYPE_PREFERENCES_GROUP)

static void
np1_xy_axis_class_init (Np1XyAxisClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanopad1/np1-xy-axis.ui");
}

static void
np1_xy_axis_init (Np1XyAxis *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
