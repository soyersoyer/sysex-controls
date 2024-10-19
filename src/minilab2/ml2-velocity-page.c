#include "ml2-velocity-page.h"

struct _Ml2VelocityPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml2VelocityPage, ml2_velocity_page, SC_TYPE_NAVIGATION_PAGE)

static void
ml2_velocity_page_class_init (Ml2VelocityPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab2/ml2-velocity-page.ui");
}

static void
ml2_velocity_page_init (Ml2VelocityPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
