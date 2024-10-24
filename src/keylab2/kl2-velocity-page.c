#include "kl2-velocity-page.h"

struct _Kl2VelocityPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl2VelocityPage, kl2_velocity_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl2_velocity_page_class_init (Kl2VelocityPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab2/kl2-velocity-page.ui");
}

static void
kl2_velocity_page_init (Kl2VelocityPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
