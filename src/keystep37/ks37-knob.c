#include "ks37-knob.h"
#include "sc-cc-row.h"

struct _Ks37Knob
{
  AdwPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Ks37Knob, ks37_knob, SC_TYPE_PREFERENCES_GROUP)


static void
ks37_knob_class_init (Ks37KnobClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keystep37/ks37-knob.ui");
}

static void
ks37_knob_init (Ks37Knob *self)
{
  g_type_ensure (SC_TYPE_CC_ROW);

  gtk_widget_init_template (GTK_WIDGET (self));
}
