#pragma once

#include <adwaita.h>

#include "ar-book.h"

#define BS_MIDI_NAME "Arturia BeatStep"
#define BS_SHORT_NAME "BeatStep"

G_BEGIN_DECLS

#define BS_TYPE_BOOK (bs_book_get_type ())

G_DECLARE_FINAL_TYPE (BsBook, bs_book, BS, BOOK, ArBook)

G_END_DECLS
