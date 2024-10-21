#include "kles3-pedal-page.h"

struct _Kles3PedalPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kles3PedalPage, kles3_pedal_page, SC_TYPE_NAVIGATION_PAGE)

static void
kles3_pedal_page_class_init (Kles3PedalPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes3/kles3-pedal-page.ui");
}

static void
kles3_pedal_page_init (Kles3PedalPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
