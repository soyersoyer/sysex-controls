#include "ks37-cc-bank-page.h"

struct _Ks37CcBankPage
{
  ScPreferencesPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ks37CcBankPage, ks37_cc_bank_page, SC_TYPE_PREFERENCES_PAGE)

static void
ks37_cc_bank_page_class_init (Ks37CcBankPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keystep37/ks37-cc-bank-page.ui");
}

static void
ks37_cc_bank_page_init (Ks37CcBankPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
