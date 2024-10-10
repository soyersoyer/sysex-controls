#include "ml3-pedal-page.h"

struct _Ml3PedalPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml3PedalPage, ml3_pedal_page, SC_TYPE_NAVIGATION_PAGE)

static void
ml3_pedal_page_class_init (Ml3PedalPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab3/ml3-pedal-page.ui");
}

static void
ml3_pedal_page_init (Ml3PedalPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
