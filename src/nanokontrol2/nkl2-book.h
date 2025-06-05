#pragma once

#include <adwaita.h>

#include "korg-book.h"
#include "sc-navigation-page.h"
#include "sc-action-row.h"

#define NKL2_MIDI_NAME "nanoKONTROL2"
#define NKL2_SHORT_NAME "nanoKONTROL2"

G_BEGIN_DECLS

#define NKL2_TYPE_BOOK (nkl2_book_get_type ())

G_DECLARE_FINAL_TYPE (Nkl2Book, nkl2_book, NKL2, BOOK, KorgBook)

void nkl2_book_on_button_activated (ScNavigationPage *page, ScActionRow* row);
void nkl2_book_on_controller_group_activated (ScNavigationPage *page, ScActionRow* row);
void nkl2_book_on_controller_groups_activated (ScNavigationPage *page, ScActionRow* row);
void nkl2_book_on_function_button_activated (ScNavigationPage *page, ScActionRow* row);
void nkl2_book_on_knob_activated (ScNavigationPage *page, ScActionRow* row);
void nkl2_book_on_slider_activated (ScNavigationPage *page, ScActionRow* row);
void nkl2_book_on_transport_buttons_activated (ScNavigationPage *page, ScActionRow* row);

G_END_DECLS
