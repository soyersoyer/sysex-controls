#include "bsp-metronome-page.h"

struct _BspMetronomePage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (BspMetronomePage, bsp_metronome_page, SC_TYPE_NAVIGATION_PAGE)

static void
bsp_metronome_page_class_init (BspMetronomePageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatsteppro/bsp-metronome-page.ui");
}

static void
bsp_metronome_page_init (BspMetronomePage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
