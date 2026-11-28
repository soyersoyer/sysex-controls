#include "nks-power-management-usb-page.h"

struct _NksPowerManagementUsbPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (NksPowerManagementUsbPage, nks_power_management_usb_page, SC_TYPE_NAVIGATION_PAGE)

static void
nks_power_management_usb_page_class_init (NksPowerManagementUsbPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokeystudio/nks-power-management-usb-page.ui");
}

static void
nks_power_management_usb_page_init (NksPowerManagementUsbPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
