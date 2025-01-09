#include "tl-aftertouch-page.h"

struct _TlAftertouchPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (TlAftertouchPage, tl_aftertouch_page, SC_TYPE_NAVIGATION_PAGE)

static void
tl_aftertouch_page_class_init (TlAftertouchPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/thelaboratory/tl-aftertouch-page.ui");
}

static void
tl_aftertouch_page_init (TlAftertouchPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
