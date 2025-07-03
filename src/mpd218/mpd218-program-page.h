#pragma once

#include <adwaita.h>

#include "ak-program-page.h"

G_BEGIN_DECLS

#define MPD218_TYPE_PROGRAM_PAGE (mpd218_program_page_get_type ())

G_DECLARE_FINAL_TYPE (Mpd218ProgramPage, mpd218_program_page, MPD218, PROGRAM_PAGE, AkProgramPage)

G_END_DECLS
