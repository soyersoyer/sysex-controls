#include "kles-velocity-page.h"

struct _KlesVelocityPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (KlesVelocityPage, kles_velocity_page, SC_TYPE_NAVIGATION_PAGE)

static void
kles_velocity_page_class_init (KlesVelocityPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes/kles-velocity-page.ui");
}

static void
kles_velocity_page_init (KlesVelocityPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
