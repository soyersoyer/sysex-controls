#include "nkls-slider-page.h"

struct _NklsSliderPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (NklsSliderPage, nkls_slider_page, SC_TYPE_NAVIGATION_PAGE)

static void
nkls_slider_page_class_init (NklsSliderPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokontrolstudio/nkls-slider-page.ui");
}

static void
nkls_slider_page_init (NklsSliderPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
