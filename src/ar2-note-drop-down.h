#pragma once

#include <adwaita.h>

G_BEGIN_DECLS

#define AR2_TYPE_NOTE_DROP_DOWN (ar2_note_drop_down_get_type ())

G_DECLARE_FINAL_TYPE (Ar2NoteDropDown, ar2_note_drop_down, AR2, NOTE_DROP_DOWN, GtkBox)

G_END_DECLS
