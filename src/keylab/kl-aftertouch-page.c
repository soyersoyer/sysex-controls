#include "kl-aftertouch-page.h"

struct _KlAftertouchPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (KlAftertouchPage, kl_aftertouch_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl_aftertouch_page_class_init (KlAftertouchPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab/kl-aftertouch-page.ui");
}

static void
kl_aftertouch_page_init (KlAftertouchPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
