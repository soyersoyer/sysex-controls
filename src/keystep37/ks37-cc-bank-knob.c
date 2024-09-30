#include "ks37-cc-bank-knob.h"

struct _Ks37CcBankKnob
{
  AdwPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Ks37CcBankKnob, ks37_cc_bank_knob, SC_TYPE_PREFERENCES_GROUP)


static void
ks37_cc_bank_knob_class_init (Ks37CcBankKnobClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keystep37/ks37-cc-bank-knob.ui");
}

static void
ks37_cc_bank_knob_init (Ks37CcBankKnob *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}

