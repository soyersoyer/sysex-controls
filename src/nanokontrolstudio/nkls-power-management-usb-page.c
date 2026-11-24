#include "nkls-power-management-usb-page.h"

struct _NklsPowerManagementUsbPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (NklsPowerManagementUsbPage, nkls_power_management_usb_page, SC_TYPE_NAVIGATION_PAGE)

static void
nkls_power_management_usb_page_class_init (NklsPowerManagementUsbPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokontrolstudio/nkls-power-management-usb-page.ui");
}

static void
nkls_power_management_usb_page_init (NklsPowerManagementUsbPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
