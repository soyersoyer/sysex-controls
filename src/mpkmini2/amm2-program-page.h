#pragma once

#include <adwaita.h>

#include "ak-program-page.h"

G_BEGIN_DECLS

#define AMM2_TYPE_PROGRAM_PAGE (amm2_program_page_get_type ())

G_DECLARE_FINAL_TYPE (Amm2ProgramPage, amm2_program_page, AMM2, PROGRAM_PAGE, AkProgramPage)

G_END_DECLS
