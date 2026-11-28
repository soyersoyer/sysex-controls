#include "nks-power-management-bat-page.h"

struct _NksPowerManagementBatPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (NksPowerManagementBatPage, nks_power_management_bat_page, SC_TYPE_NAVIGATION_PAGE)

static void
nks_power_management_bat_page_class_init (NksPowerManagementBatPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokeystudio/nks-power-management-bat-page.ui");
}

static void
nks_power_management_bat_page_init (NksPowerManagementBatPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
