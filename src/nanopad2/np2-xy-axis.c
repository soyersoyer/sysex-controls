#include "np2-xy-axis.h"

struct _Np2XyAxis
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Np2XyAxis, np2_xy_axis, SC_TYPE_PREFERENCES_GROUP)

static void
np2_xy_axis_class_init (Np2XyAxisClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanopad2/np2-xy-axis.ui");
}

static void
np2_xy_axis_init (Np2XyAxis *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
