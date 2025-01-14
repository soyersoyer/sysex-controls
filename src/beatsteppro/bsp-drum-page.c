#include "bsp-drum-page.h"

struct _BspDrumPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (BspDrumPage, bsp_drum_page, SC_TYPE_NAVIGATION_PAGE)

static void
bsp_drum_page_class_init (BspDrumPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatsteppro/bsp-drum-page.ui");
}

static void
bsp_drum_page_init (BspDrumPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
