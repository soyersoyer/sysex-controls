#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define MATR_TYPE_GENERAL_PAGE (matr_general_page_get_type ())

G_DECLARE_FINAL_TYPE (MatrGeneralPage, matr_general_page, MATR, GENERAL_PAGE, ScNavigationPage)

G_END_DECLS
