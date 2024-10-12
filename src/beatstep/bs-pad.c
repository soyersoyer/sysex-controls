#include "bs-pad.h"

struct _BsPad
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (BsPad, bs_pad, SC_TYPE_PREFERENCES_GROUP)

static void
bs_pad_class_init (BsPadClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatstep/bs-pad.ui");
}

static void
bs_pad_init (BsPad *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
