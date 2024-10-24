#include "kl2-bank-page.h"

#include "kl2-kfs-page.h"

struct _Kl2BankPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl2BankPage, kl2_bank_page, SC_TYPE_NAVIGATION_PAGE)

void
kl2_bank_page_on_row_activated (Kl2BankPage *self, ScActionRow *row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *page = g_object_new (KL2_TYPE_KFS_PAGE,
                                          "title", adw_preferences_row_get_title(ADW_PREFERENCES_ROW (row)),
                                          "control-id-offset", sc_action_row_get_control_id_offset (row),
                                          NULL);
  adw_navigation_view_push (view, page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), page);
}


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
