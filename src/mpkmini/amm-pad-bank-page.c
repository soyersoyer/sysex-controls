#include "amm-pad-bank-page.h"

struct _AmmPadBankPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (AmmPadBankPage, amm_pad_bank_page, SC_TYPE_NAVIGATION_PAGE)

static void
amm_pad_bank_page_class_init (AmmPadBankPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/mpkmini/amm-pad-bank-page.ui");
}

static void
amm_pad_bank_page_init (AmmPadBankPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
