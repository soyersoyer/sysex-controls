#include "amm3-keybed-page.h"

struct _Amm3KeybedPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Amm3KeybedPage, amm3_keybed_page, SC_TYPE_NAVIGATION_PAGE)

static void
amm3_keybed_page_class_init (Amm3KeybedPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/mpkmini3/amm3-keybed-page.ui");
}

static void
amm3_keybed_page_init (Amm3KeybedPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
