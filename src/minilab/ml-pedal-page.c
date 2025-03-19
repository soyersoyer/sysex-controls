#include "ml-pedal-page.h"

struct _MlPedalPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (MlPedalPage, ml_pedal_page, SC_TYPE_NAVIGATION_PAGE)

static void
ml_pedal_page_class_init (MlPedalPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab/ml-pedal-page.ui");
}

static void
ml_pedal_page_init (MlPedalPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
