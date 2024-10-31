#include "amm3-arpeggiator-page.h"

struct _Amm3ArpeggiatorPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Amm3ArpeggiatorPage, amm3_arpeggiator_page, SC_TYPE_NAVIGATION_PAGE)

static void
amm3_arpeggiator_page_class_init (Amm3ArpeggiatorPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/mpkmini3/amm3-arpeggiator-page.ui");
}

static void
amm3_arpeggiator_page_init (Amm3ArpeggiatorPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
