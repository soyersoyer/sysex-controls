#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKL2_TYPE_SLIDER_PAGE (nkl2_slider_page_get_type ())

G_DECLARE_FINAL_TYPE (Nkl2SliderPage, nkl2_slider_page, NKL2, SLIDER_PAGE, ScNavigationPage)

G_END_DECLS
