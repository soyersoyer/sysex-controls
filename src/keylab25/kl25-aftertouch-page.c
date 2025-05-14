#include "kl25-aftertouch-page.h"

struct _Kl25AftertouchPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl25AftertouchPage, kl25_aftertouch_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl25_aftertouch_page_class_init (Kl25AftertouchPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab25/kl25-aftertouch-page.ui");
}

static void
kl25_aftertouch_page_init (Kl25AftertouchPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
