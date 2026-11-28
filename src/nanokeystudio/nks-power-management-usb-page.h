#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKS_TYPE_POWER_MANAGEMENT_USB_PAGE (nks_power_management_usb_page_get_type ())

G_DECLARE_FINAL_TYPE (NksPowerManagementUsbPage, nks_power_management_usb_page, NKS, POWER_MANAGEMENT_USB_PAGE, ScNavigationPage)

G_END_DECLS
