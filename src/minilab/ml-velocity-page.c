#include "ml-velocity-page.h"

struct _MlVelocityPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (MlVelocityPage, ml_velocity_page, SC_TYPE_NAVIGATION_PAGE)

static void
ml_velocity_page_class_init (MlVelocityPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab/ml-velocity-page.ui");
}

static void
ml_velocity_page_init (MlVelocityPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
