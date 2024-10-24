#include "kl2-pedal-page.h"

struct _Kl2PedalPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl2PedalPage, kl2_pedal_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl2_pedal_page_class_init (Kl2PedalPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab2/kl2-pedal-page.ui");
}

static void
kl2_pedal_page_init (Kl2PedalPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
