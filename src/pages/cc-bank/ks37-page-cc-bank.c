#include "ks37-page-cc-bank.h"
#include "ks37-page-cc-bank-knob.h"

struct _Ks37PageCcBank
{
	AdwPreferencesPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ks37PageCcBank, ks37_page_cc_bank, KS37_TYPE_PREFERENCES_PAGE)


static void
ks37_page_cc_bank_class_init (Ks37PageCcBankClass *klass)
{
	GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

	gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/keystep37-settings/pages/cc-bank/ks37-page-cc-bank.ui");
}

static void
ks37_page_cc_bank_init (Ks37PageCcBank *self)
{
	g_type_ensure (KS37_TYPE_PAGE_CC_BANK_KNOB);

	gtk_widget_init_template (GTK_WIDGET (self));
}

