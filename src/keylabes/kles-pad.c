#include "kles-pad.h"

struct _KlesPad
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (KlesPad, kles_pad, SC_TYPE_PREFERENCES_GROUP)

static void
kles_pad_class_init (KlesPadClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes/kles-pad.ui");
}

static void
kles_pad_init (KlesPad *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
