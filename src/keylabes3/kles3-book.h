#pragma once

#include <adwaita.h>

#include "ar-book.h"
#include "sc-navigation-page.h"
#include "sc-action-row.h"

#define KLES3_49_MIDI_NAME "KL Essential 49 mk3"
#define KLES3_49_SHORT_NAME "KeyLab ES 49 mk3"

#define KLES3_61_MIDI_NAME "KL Essential 61 mk3"
#define KLES3_61_SHORT_NAME "KeyLab ES 61 mk3"

#define KLES3_88_MIDI_NAME "KL Essential 88 mk3"
#define KLES3_88_SHORT_NAME "KeyLab ES 88 mk3"

G_BEGIN_DECLS

#define KLES3_TYPE_BOOK (kles3_book_get_type ())

G_DECLARE_FINAL_TYPE (Kles3Book, kles3_book, KLES3, BOOK, ArBook)

void kles3_book_on_presets_preset_activated (ScNavigationPage *page, ScActionRow *row);

void kles3_book_on_preset_pitch_mod_activated (ScNavigationPage *page, ScActionRow* row);
void kles3_book_on_preset_main_knob_activated (ScNavigationPage *page, ScActionRow* row);
void kles3_book_on_preset_knob_activated (ScNavigationPage *page, ScActionRow* row);
void kles3_book_on_preset_button_activated (ScNavigationPage *page, ScActionRow* row);
void kles3_book_on_preset_fader_activated (ScNavigationPage *page, ScActionRow* row);
void kles3_book_on_preset_pad_a_activated (ScNavigationPage *page, ScActionRow* row);
void kles3_book_on_preset_pad_b_activated (ScNavigationPage *page, ScActionRow* row);

G_END_DECLS
