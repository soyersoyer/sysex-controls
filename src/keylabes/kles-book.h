#pragma once

#include <adwaita.h>

#include "ar-book.h"
#include "sc-action-row.h"
#include "sc-navigation-page.h"

#define KLES_49_MIDI_NAME "Arturia KeyLab Essential 49"
#define KLES_49_SHORT_NAME "KeyLab ES 49"

#define KLES_61_MIDI_NAME "Arturia KeyLab Essential 61"
#define KLES_61_SHORT_NAME "KeyLab ES 61"

#define KLES_88_MIDI_NAME "Arturia KeyLab Essential 88"
#define KLES_88_SHORT_NAME "KeyLab ES 88"

G_BEGIN_DECLS

#define KLES_TYPE_BOOK (kles_book_get_type ())

G_DECLARE_FINAL_TYPE (KlesBook, kles_book, KLES, BOOK, ArBook)

void kles_book_on_presets_preset_activated (ScNavigationPage *page, ScActionRow *row);

void kles_book_on_preset_keyboard_activated (ScNavigationPage *page, ScActionRow* row);
void kles_book_on_preset_pedal_activated (ScNavigationPage *page, ScActionRow* row);
void kles_book_on_preset_pad_activated (ScNavigationPage *page, ScActionRow* row);
void kles_book_on_preset_button_activated (ScNavigationPage *page, ScActionRow* row);
void kles_book_on_preset_knob_activated (ScNavigationPage *page, ScActionRow* row);
void kles_book_on_preset_fader_activated (ScNavigationPage *page, ScActionRow* row);

G_END_DECLS
