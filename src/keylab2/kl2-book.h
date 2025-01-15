#pragma once

#include <adwaita.h>

#include "ar-book.h"
#include "sc-action-row.h"
#include "sc-navigation-page.h"

#define KL2_49_MIDI_NAME "KeyLab mkII 49"
#define KL2_49_SHORT_NAME "KL mkII 49"

#define KL2_61_MIDI_NAME "KeyLab mkII 61"
#define KL2_61_SHORT_NAME "KL mkII 61"

#define KL2_88_MIDI_NAME "KeyLab mkII 88"
#define KL2_88_SHORT_NAME "KL mkII 88"

G_BEGIN_DECLS

#define KL2_TYPE_BOOK (kl2_book_get_type ())

G_DECLARE_FINAL_TYPE (Kl2Book, kl2_book, KL2, BOOK, ArBook)

void kl2_book_on_presets_preset_activated (ScNavigationPage *page, ScActionRow *row);

void kl2_book_on_preset_keyboard_activated (ScNavigationPage *page, ScActionRow* row);
void kl2_book_on_preset_pitch_mod_activated (ScNavigationPage *page, ScActionRow* row);
void kl2_book_on_preset_pedal_activated (ScNavigationPage *page, ScActionRow* row);
void kl2_book_on_preset_cv_activated (ScNavigationPage *page, ScActionRow* row);
void kl2_book_on_preset_bank_activated (ScNavigationPage *page, ScActionRow* row);
void kl2_book_on_preset_pad_activated (ScNavigationPage *page, ScActionRow* row);
void kl2_book_on_preset_daw_buttons_activated (ScNavigationPage *page, ScActionRow* row);

void kl2_book_on_preset_bank_column_activated (ScNavigationPage *page, ScActionRow *row);

G_END_DECLS
