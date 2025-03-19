#pragma once

#include <adwaita.h>

#include "ar-book.h"
#include "sc-action-row.h"
#include "sc-navigation-page.h"

#define ML_MIDI_NAME "Arturia MINILAB"
#define ML_SHORT_NAME "MiniLab"

G_BEGIN_DECLS

#define ML_TYPE_BOOK (ml_book_get_type ())

G_DECLARE_FINAL_TYPE (MlBook, ml_book, ML, BOOK, ArBook)

void ml_book_on_presets_preset_activated (ScNavigationPage *page, ScActionRow *row);
void ml_book_on_presets_ar_presets_activated (ScNavigationPage *page, ScActionRow *row);

void ml_book_on_preset_pitch_mod_activated (ScNavigationPage *page, ScActionRow* row);
void ml_book_on_preset_pedal_activated (ScNavigationPage *page, ScActionRow* row);
void ml_book_on_preset_knob_activated (ScNavigationPage *page, ScActionRow* row);
void ml_book_on_preset_pad_activated (ScNavigationPage *page, ScActionRow* row);

G_END_DECLS
