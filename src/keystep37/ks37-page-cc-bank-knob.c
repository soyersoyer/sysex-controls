#include "ks37-page-cc-bank-knob.h"

struct _Ks37PageCcBankKnob
{
  AdwPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Ks37PageCcBankKnob, ks37_page_cc_bank_knob, SC_TYPE_PREFERENCES_GROUP)


static void
ks37_page_cc_bank_knob_class_init (Ks37PageCcBankKnobClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keystep37/ks37-page-cc-bank-knob.ui");
}

static void
ks37_page_cc_bank_knob_init (Ks37PageCcBankKnob *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}

