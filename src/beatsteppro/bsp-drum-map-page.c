#include "bsp-drum-map-page.h"

struct _BspDrumMapPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (BspDrumMapPage, bsp_drum_map_page, SC_TYPE_NAVIGATION_PAGE)

static void
bsp_drum_map_page_class_init (BspDrumMapPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatsteppro/bsp-drum-map-page.ui");
}

static void
bsp_drum_map_page_init (BspDrumMapPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
