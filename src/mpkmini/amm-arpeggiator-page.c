#include "amm-arpeggiator-page.h"

struct _AmmArpeggiatorPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (AmmArpeggiatorPage, amm_arpeggiator_page, SC_TYPE_NAVIGATION_PAGE)

static void
amm_arpeggiator_page_class_init (AmmArpeggiatorPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/mpkmini/amm-arpeggiator-page.ui");
}

static void
amm_arpeggiator_page_init (AmmArpeggiatorPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
