#include "bsp-projects-page.h"

struct _BspProjectsPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (BspProjectsPage, bsp_projects_page, SC_TYPE_NAVIGATION_PAGE)

static void
bsp_projects_page_class_init (BspProjectsPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatsteppro/bsp-projects-page.ui");
}

static void
bsp_projects_page_init (BspProjectsPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
