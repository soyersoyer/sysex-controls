#include "ml3-velocity-page.h"

struct _Ml3VelocityPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml3VelocityPage, ml3_velocity_page, SC_TYPE_NAVIGATION_PAGE)

static void
ml3_velocity_page_class_init (Ml3VelocityPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab3/ml3-velocity-page.ui");
}

static void
ml3_velocity_page_init (Ml3VelocityPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
