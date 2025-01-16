#include "kl88-aftertouch-page.h"

struct _Kl88AftertouchPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl88AftertouchPage, kl88_aftertouch_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl88_aftertouch_page_class_init (Kl88AftertouchPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab88/kl88-aftertouch-page.ui");
}

static void
kl88_aftertouch_page_init (Kl88AftertouchPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
