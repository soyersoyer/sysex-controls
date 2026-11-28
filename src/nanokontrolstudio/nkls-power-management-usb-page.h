#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKLS_TYPE_POWER_MANAGEMENT_USB_PAGE (nkls_power_management_usb_page_get_type ())

G_DECLARE_FINAL_TYPE (NklsPowerManagementUsbPage, nkls_power_management_usb_page, NKLS, POWER_MANAGEMENT_USB_PAGE, ScNavigationPage)

G_END_DECLS
