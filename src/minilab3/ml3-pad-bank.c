#include "ml3-pad-bank.h"

struct _Ml3PadBank
{
  ScPreferencesPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml3PadBank, ml3_pad_bank, SC_TYPE_PREFERENCES_PAGE)

static void
ml3_pad_bank_class_init (Ml3PadBankClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab3/ml3-pad-bank.ui");
}

static void
ml3_pad_bank_init (Ml3PadBank *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
