#include "nkls-power-management-bat-page.h"

struct _NklsPowerManagementBatPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (NklsPowerManagementBatPage, nkls_power_management_bat_page, SC_TYPE_NAVIGATION_PAGE)

static void
nkls_power_management_bat_page_class_init (NklsPowerManagementBatPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokontrolstudio/nkls-power-management-bat-page.ui");
}

static void
nkls_power_management_bat_page_init (NklsPowerManagementBatPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
