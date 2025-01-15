#pragma once

#include <adwaita.h>

#include "ar-book.h"
#include "sc-action-row.h"
#include "sc-navigation-page.h"

#define ML2_MIDI_NAME "Arturia MiniLab mkII"
#define ML2_SHORT_NAME "ML mkII"

G_BEGIN_DECLS

#define ML2_TYPE_BOOK (ml2_book_get_type ())

G_DECLARE_FINAL_TYPE (Ml2Book, ml2_book, ML2, BOOK, ArBook)

void ml2_book_on_presets_preset_activated (ScNavigationPage *page, ScActionRow *row);
void ml2_book_on_presets_ar_presets_activated (ScNavigationPage *page, ScActionRow *row);

void ml2_book_on_preset_pitch_mod_activated (ScNavigationPage *page, ScActionRow* row);
void ml2_book_on_preset_pedal_activated (ScNavigationPage *page, ScActionRow* row);
void ml2_book_on_preset_knob_activated (ScNavigationPage *page, ScActionRow* row);
void ml2_book_on_preset_knob_extra_activated (ScNavigationPage *page, ScActionRow* row);
void ml2_book_on_preset_pad_activated (ScNavigationPage *page, ScActionRow* row);

G_END_DECLS
