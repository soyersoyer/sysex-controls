#include "bsp-project-page.h"

struct _BspProjectPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (BspProjectPage, bsp_project_page, SC_TYPE_NAVIGATION_PAGE)

static void
bsp_project_page_class_init (BspProjectPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatsteppro/bsp-project-page.ui");
}

static void
bsp_project_page_init (BspProjectPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
