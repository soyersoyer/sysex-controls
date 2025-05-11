#pragma once

#include <adwaita.h>

#include "ak-program-page.h"

G_BEGIN_DECLS

#define AMM_TYPE_PROGRAM_PAGE (amm_program_page_get_type ())

G_DECLARE_FINAL_TYPE (AmmProgramPage, amm_program_page, AMM, PROGRAM_PAGE, AkProgramPage)

G_END_DECLS
