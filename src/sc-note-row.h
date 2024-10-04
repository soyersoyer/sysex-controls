#pragma once

#include <adwaita.h>

#include "sc-combo-row.h"

G_BEGIN_DECLS

#define SC_TYPE_NOTE_ROW (sc_note_row_get_type ())

G_DECLARE_FINAL_TYPE (ScNoteRow, sc_note_row, SC, NOTE_ROW, ScComboRow)

G_END_DECLS
