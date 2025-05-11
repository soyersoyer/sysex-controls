#pragma once

#include <adwaita.h>

#include "ak-book.h"
#include "sc-navigation-page.h"
#include "sc-action-row.h"

#define AMM_MIDI_NAME "MPK mini"
#define AMM_SHORT_NAME "MPK mini"

G_BEGIN_DECLS

#define AMM_TYPE_BOOK (amm_book_get_type ())

G_DECLARE_FINAL_TYPE (AmmBook, amm_book, AMM, BOOK, AkBook)

void amm_book_on_arpeggiator_activated (ScNavigationPage *self, ScActionRow* row);
void amm_book_on_keybed_activated (ScNavigationPage *self, ScActionRow* row);
void amm_book_on_knob_activated (ScNavigationPage *self, ScActionRow* row);
void amm_book_on_pad_activated (ScNavigationPage *self, ScActionRow* row);
void amm_book_on_pad_bank_activated (ScNavigationPage *self, ScActionRow* row);

G_END_DECLS
