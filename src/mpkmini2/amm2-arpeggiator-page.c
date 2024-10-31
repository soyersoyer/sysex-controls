#include "amm2-arpeggiator-page.h"

struct _Amm2ArpeggiatorPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Amm2ArpeggiatorPage, amm2_arpeggiator_page, SC_TYPE_NAVIGATION_PAGE)

static void
amm2_arpeggiator_page_class_init (Amm2ArpeggiatorPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/mpkmini2/amm2-arpeggiator-page.ui");
}

static void
amm2_arpeggiator_page_init (Amm2ArpeggiatorPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
