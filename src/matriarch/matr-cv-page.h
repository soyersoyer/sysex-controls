#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define MATR_TYPE_CV_PAGE (matr_cv_page_get_type ())

G_DECLARE_FINAL_TYPE (MatrCvPage, matr_cv_page, MATR, CV_PAGE, ScNavigationPage)

G_END_DECLS
