#pragma once

#include <adwaita.h>

#include "sc-combo-row.h"

G_BEGIN_DECLS

#define KORG_TYPE_NOTE_OFFSET_ROW (korg_note_offset_row_get_type ())

G_DECLARE_FINAL_TYPE (KorgNoteOffsetRow, korg_note_offset_row, KORG, NOTE_OFFSET_ROW, ScComboRow)

G_END_DECLS
