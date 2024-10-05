#include "ml2-pad.h"

struct _Ml2Pad
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml2Pad, ml2_pad, SC_TYPE_PREFERENCES_GROUP)

static void
ml2_pad_class_init (Ml2PadClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab2/ml2-pad.ui");
}

static void
ml2_pad_init (Ml2Pad *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
