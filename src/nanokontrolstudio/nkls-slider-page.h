#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKLS_TYPE_SLIDER_PAGE (nkls_slider_page_get_type ())

G_DECLARE_FINAL_TYPE (NklsSliderPage, nkls_slider_page, NKLS, SLIDER_PAGE, ScNavigationPage)

G_END_DECLS
