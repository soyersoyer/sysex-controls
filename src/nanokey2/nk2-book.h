#pragma once

#include <adwaita.h>

#include "korg-book.h"
#include "sc-navigation-page.h"
#include "sc-action-row.h"

#define NK2_MIDI_NAME "nanoKEY2"
#define NK2_SHORT_NAME "nanoKEY2"

G_BEGIN_DECLS

#define NK2_TYPE_BOOK (nk2_book_get_type ())

G_DECLARE_FINAL_TYPE (Nk2Book, nk2_book, NK2, BOOK, KorgBook)

void nk2_book_on_button_activated (ScNavigationPage *page, ScActionRow* row);
void nk2_book_on_keyboard_activated (ScNavigationPage *page, ScActionRow* row);
void nk2_book_on_pitch_bend_activated (ScNavigationPage *page, ScActionRow* row);

G_END_DECLS
