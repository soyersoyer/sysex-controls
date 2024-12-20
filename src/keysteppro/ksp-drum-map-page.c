#include "ksp-drum-map-page.h"

struct _KspDrumMapPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (KspDrumMapPage, ksp_drum_map_page, SC_TYPE_NAVIGATION_PAGE)

static void
ksp_drum_map_page_class_init (KspDrumMapPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keysteppro/ksp-drum-map-page.ui");
}

static void
ksp_drum_map_page_init (KspDrumMapPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
