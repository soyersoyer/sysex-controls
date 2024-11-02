#pragma once

#include <adwaita.h>

G_BEGIN_DECLS

#define AK_TYPE_PROGRAM_SELECT (ak_program_select_get_type ())

G_DECLARE_FINAL_TYPE (AkProgramSelect, ak_program_select, AK, PROGRAM_SELECT, GtkButton)

void ak_program_select_clicked (AkProgramSelect *self);

G_END_DECLS
