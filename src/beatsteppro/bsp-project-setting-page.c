#include "bsp-project-setting-page.h"

struct _BspProjectSettingPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (BspProjectSettingPage, bsp_project_setting_page, SC_TYPE_NAVIGATION_PAGE)

static void
bsp_project_setting_page_class_init (BspProjectSettingPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatsteppro/bsp-project-setting-page.ui");
}

static void
bsp_project_setting_page_init (BspProjectSettingPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
