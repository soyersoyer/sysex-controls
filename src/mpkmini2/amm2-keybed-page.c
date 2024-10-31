#include "amm2-keybed-page.h"

struct _Amm2KeybedPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Amm2KeybedPage, amm2_keybed_page, SC_TYPE_NAVIGATION_PAGE)

static void
amm2_keybed_page_class_init (Amm2KeybedPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/mpkmini2/amm2-keybed-page.ui");
}

static void
amm2_keybed_page_init (Amm2KeybedPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
