#include "kles3-velocity-page.h"

struct _Kles3VelocityPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kles3VelocityPage, kles3_velocity_page, SC_TYPE_NAVIGATION_PAGE)

static void
kles3_velocity_page_class_init (Kles3VelocityPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes3/kles3-velocity-page.ui");
}

static void
kles3_velocity_page_init (Kles3VelocityPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
