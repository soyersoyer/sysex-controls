#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define MATR_TYPE_DELAY_PAGE (matr_delay_page_get_type ())

G_DECLARE_FINAL_TYPE (MatrDelayPage, matr_delay_page, MATR, DELAY_PAGE, ScNavigationPage)

G_END_DECLS
