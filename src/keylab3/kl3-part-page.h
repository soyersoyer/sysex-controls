#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL3_TYPE_PART_PAGE (kl3_part_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl3PartPage, kl3_part_page, KL3, PART_PAGE, ScNavigationPage)

G_END_DECLS
