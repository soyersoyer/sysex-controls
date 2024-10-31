#pragma once

#include <adwaita.h>

#include "ak-book.h"
#include "sc-navigation-page.h"
#include "sc-action-row.h"

#define AMM2_MIDI_NAME "MPKmini2"
#define AMM2_SHORT_NAME "MPK mini 2"

G_BEGIN_DECLS

#define AMM2_TYPE_BOOK (amm2_book_get_type ())

G_DECLARE_FINAL_TYPE (Amm2Book, amm2_book, AMM2, BOOK, AkBook)

GtkWidget * amm2_book_new (void);

void amm2_book_on_arpeggiator_activated (ScNavigationPage *self, ScActionRow* row);
void amm2_book_on_joystick_activated (ScNavigationPage *self, ScActionRow* row);
void amm2_book_on_keybed_activated (ScNavigationPage *self, ScActionRow* row);
void amm2_book_on_knob_activated (ScNavigationPage *self, ScActionRow* row);
void amm2_book_on_pad_activated (ScNavigationPage *self, ScActionRow* row);
void amm2_book_on_pad_bank_activated (ScNavigationPage *self, ScActionRow* row);

G_END_DECLS
