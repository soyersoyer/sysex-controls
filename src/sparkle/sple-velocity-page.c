#include "sple-velocity-page.h"

struct _SpleVelocityPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (SpleVelocityPage, sple_velocity_page, SC_TYPE_NAVIGATION_PAGE)

static void
sple_velocity_page_class_init (SpleVelocityPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/sparkle/sple-velocity-page.ui");
}

static void
sple_velocity_page_init (SpleVelocityPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
