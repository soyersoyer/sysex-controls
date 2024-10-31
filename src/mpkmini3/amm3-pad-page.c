#include "amm3-pad-page.h"

struct _Amm3PadPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Amm3PadPage, amm3_pad_page, SC_TYPE_NAVIGATION_PAGE)

static void
amm3_pad_page_class_init (Amm3PadPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/mpkmini3/amm3-pad-page.ui");
}

static void
amm3_pad_page_init (Amm3PadPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
