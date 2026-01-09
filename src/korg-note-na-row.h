#pragma once

#include <adwaita.h>

#include "sc-combo-row.h"

G_BEGIN_DECLS

#define KORG_TYPE_NOTE_NA_ROW (korg_note_na_row_get_type ())

G_DECLARE_FINAL_TYPE (KorgNoteNaRow, korg_note_na_row, KORG, NOTE_NA_ROW, ScComboRow)

G_END_DECLS
