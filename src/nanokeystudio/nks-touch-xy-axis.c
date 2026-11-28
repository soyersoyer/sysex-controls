#include "nks-touch-xy-axis.h"

struct _NksTouchXyAxis
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (NksTouchXyAxis, nks_touch_xy_axis, SC_TYPE_PREFERENCES_GROUP)

static void
nks_touch_xy_axis_class_init (NksTouchXyAxisClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokeystudio/nks-touch-xy-axis.ui");
}

static void
nks_touch_xy_axis_init (NksTouchXyAxis *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
