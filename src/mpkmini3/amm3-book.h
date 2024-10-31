#pragma once

#include <adwaita.h>

#include "ak-book.h"
#include "sc-navigation-page.h"
#include "sc-action-row.h"

#define AMM3_MIDI_NAME "MPK mini 3"
#define AMM3_SHORT_NAME "MPK mini 3"

G_BEGIN_DECLS

#define AMM3_TYPE_BOOK (amm3_book_get_type ())

G_DECLARE_FINAL_TYPE (Amm3Book, amm3_book, AMM3, BOOK, AkBook)

GtkWidget * amm3_book_new (void);

void amm3_book_on_arpeggiator_activated (ScNavigationPage *self, ScActionRow* row);
void amm3_book_on_joystick_activated (ScNavigationPage *self, ScActionRow* row);
void amm3_book_on_keybed_activated (ScNavigationPage *self, ScActionRow* row);
void amm3_book_on_knob_activated (ScNavigationPage *self, ScActionRow* row);
void amm3_book_on_pad_activated (ScNavigationPage *self, ScActionRow* row);
void amm3_book_on_pad_bank_activated (ScNavigationPage *self, ScActionRow* row);

G_END_DECLS
