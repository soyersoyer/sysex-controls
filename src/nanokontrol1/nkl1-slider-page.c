#include "nkl1-slider-page.h"

struct _Nkl1SliderPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Nkl1SliderPage, nkl1_slider_page, SC_TYPE_NAVIGATION_PAGE)

static void
nkl1_slider_page_class_init (Nkl1SliderPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokontrol1/nkl1-slider-page.ui");
}

static void
nkl1_slider_page_init (Nkl1SliderPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
