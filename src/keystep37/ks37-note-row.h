#pragma once

#include <adwaita.h>

#include "sc-combo-row.h"

G_BEGIN_DECLS

#define KS37_TYPE_NOTE_ROW (ks37_note_row_get_type ())

G_DECLARE_FINAL_TYPE (Ks37NoteRow, ks37_note_row, KS37, NOTE_ROW, ScComboRow)

G_END_DECLS
