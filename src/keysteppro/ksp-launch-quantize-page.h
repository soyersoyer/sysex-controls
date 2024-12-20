#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KSP_TYPE_LAUNCH_QUANTIZE_PAGE (ksp_launch_quantize_page_get_type ())

G_DECLARE_FINAL_TYPE (KspLaunchQuantizePage, ksp_launch_quantize_page, KSP, LAUNCH_QUANTIZE_PAGE, ScNavigationPage)

G_END_DECLS
