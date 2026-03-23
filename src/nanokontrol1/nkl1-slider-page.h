#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKL1_TYPE_SLIDER_PAGE (nkl1_slider_page_get_type ())

G_DECLARE_FINAL_TYPE (Nkl1SliderPage, nkl1_slider_page, NKL1, SLIDER_PAGE, ScNavigationPage)

G_END_DECLS
