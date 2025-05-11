#include "amm-keybed-page.h"

struct _AmmKeybedPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (AmmKeybedPage, amm_keybed_page, SC_TYPE_NAVIGATION_PAGE)

static void
amm_keybed_page_class_init (AmmKeybedPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/mpkmini/amm-keybed-page.ui");
}

static void
amm_keybed_page_init (AmmKeybedPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
