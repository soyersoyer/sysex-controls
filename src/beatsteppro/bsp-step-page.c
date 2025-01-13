#include "bsp-step-page.h"

struct _BspStepPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (BspStepPage, bsp_step_page, SC_TYPE_NAVIGATION_PAGE)

static void
bsp_step_page_class_init (BspStepPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatsteppro/bsp-step-page.ui");
}

static void
bsp_step_page_init (BspStepPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
