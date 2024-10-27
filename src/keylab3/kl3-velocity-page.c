#include "kl3-velocity-page.h"

struct _Kl3VelocityPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl3VelocityPage, kl3_velocity_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl3_velocity_page_class_init (Kl3VelocityPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab3/kl3-velocity-page.ui");
}

static void
kl3_velocity_page_init (Kl3VelocityPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
