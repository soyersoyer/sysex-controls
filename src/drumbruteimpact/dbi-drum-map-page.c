#include "dbi-drum-map-page.h"

struct _DbiDrumMapPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (DbiDrumMapPage, dbi_drum_map_page, SC_TYPE_NAVIGATION_PAGE)

static void
dbi_drum_map_page_class_init (DbiDrumMapPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/drumbruteimpact/dbi-drum-map-page.ui");
}

static void
dbi_drum_map_page_init (DbiDrumMapPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
