#include "bsp-pad-page.h"

struct _BspPadPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (BspPadPage, bsp_pad_page, SC_TYPE_NAVIGATION_PAGE)

static void
bsp_pad_page_class_init (BspPadPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatsteppro/bsp-pad-page.ui");
}

static void
bsp_pad_page_init (BspPadPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
