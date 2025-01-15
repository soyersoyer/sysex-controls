#include "kl2-bank-page.h"

struct _Kl2BankPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl2BankPage, kl2_bank_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl2_bank_page_class_init (Kl2BankPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab2/kl2-bank-page.ui");
}

static void
kl2_bank_page_init (Kl2BankPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
