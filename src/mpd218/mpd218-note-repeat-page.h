#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define MPD218_TYPE_NOTE_REPEAT_PAGE (mpd218_note_repeat_page_get_type ())

G_DECLARE_FINAL_TYPE (Mpd218NoteRepeatPage, mpd218_note_repeat_page, MPD218, NOTE_REPEAT_PAGE, ScNavigationPage)

G_END_DECLS
