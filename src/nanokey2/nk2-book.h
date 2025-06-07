#pragma once

#include <adwaita.h>

#include "korg-book.h"

#define NK2_MIDI_NAME "nanoKEY2"
#define NK2_SHORT_NAME "nanoKEY2"

G_BEGIN_DECLS

#define NK2_TYPE_BOOK (nk2_book_get_type ())

G_DECLARE_FINAL_TYPE (Nk2Book, nk2_book, NK2, BOOK, KorgBook)

G_END_DECLS
