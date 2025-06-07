#pragma once

#include <adwaita.h>

#include "ar-book.h"
#include "sc-action-row.h"
#include "sc-navigation-page.h"

#define ML3_MIDI_NAME "Minilab3"
#define ML3_SHORT_NAME "MiniLab 3"

G_BEGIN_DECLS

#define ML3_TYPE_BOOK (ml3_book_get_type ())

G_DECLARE_FINAL_TYPE (Ml3Book, ml3_book, ML3, BOOK, ArBook)

void ml3_book_on_presets_preset_activated (ScNavigationPage *page, ScActionRow *row);
void ml3_book_on_presets_preset_selected_activated (ScNavigationPage *page, ScActionRow *row);

void ml3_book_on_preset_spm_activated (ScNavigationPage *page, ScActionRow* row);
void ml3_book_on_preset_main_knob_activated (ScNavigationPage *page, ScActionRow* row);
void ml3_book_on_preset_knob_activated (ScNavigationPage *page, ScActionRow* row);
void ml3_book_on_preset_fader_activated (ScNavigationPage *page, ScActionRow* row);
void ml3_book_on_preset_pad_activated (ScNavigationPage *page, ScActionRow* row);

G_END_DECLS
