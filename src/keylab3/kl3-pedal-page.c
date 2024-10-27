#include "kl3-pedal-page.h"

struct _Kl3PedalPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl3PedalPage, kl3_pedal_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl3_pedal_page_class_init (Kl3PedalPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab3/kl3-pedal-page.ui");
}

static void
kl3_pedal_page_init (Kl3PedalPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
