#include "microlab3-pedal-page.h"

struct _Microlab3PedalPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Microlab3PedalPage, microlab3_pedal_page, SC_TYPE_NAVIGATION_PAGE)

static void
microlab3_pedal_page_class_init (Microlab3PedalPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/microlab3/microlab3-pedal-page.ui");
}

static void
microlab3_pedal_page_init (Microlab3PedalPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
