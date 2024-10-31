#pragma once

#include <adwaita.h>

#include "ak-program-page.h"

G_BEGIN_DECLS

#define AMM3_TYPE_PROGRAM_PAGE (amm3_program_page_get_type ())

G_DECLARE_FINAL_TYPE (Amm3ProgramPage, amm3_program_page, AMM3, PROGRAM_PAGE, AkProgramPage)

G_END_DECLS
