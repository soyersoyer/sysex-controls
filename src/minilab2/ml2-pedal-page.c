#include "ml2-pedal-page.h"

struct _Ml2PedalPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml2PedalPage, ml2_pedal_page, SC_TYPE_NAVIGATION_PAGE)

static void
ml2_pedal_page_class_init (Ml2PedalPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab2/ml2-pedal-page.ui");
}

static void
ml2_pedal_page_init (Ml2PedalPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
