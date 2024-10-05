#include "ml2-pad-bank.h"

struct _Ml2PadBank
{
  ScPreferencesPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml2PadBank, ml2_pad_bank, SC_TYPE_PREFERENCES_PAGE)

static void
ml2_pad_bank_class_init (Ml2PadBankClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab2/ml2-pad-bank.ui");
}

static void
ml2_pad_bank_init (Ml2PadBank *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
