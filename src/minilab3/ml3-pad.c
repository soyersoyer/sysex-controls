#include "ml3-pad.h"

struct _Ml3Pad
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml3Pad, ml3_pad, SC_TYPE_PREFERENCES_GROUP)

static void
ml3_pad_class_init (Ml3PadClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab3/ml3-pad.ui");
}

static void
ml3_pad_init (Ml3Pad *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
