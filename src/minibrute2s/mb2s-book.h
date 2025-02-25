#pragma once

#include <adwaita.h>

#include "ar-book.h"

#define MB2S_MIDI_NAME "Arturia MiniBrute 2S"
#define MB2S_SHORT_NAME "MiniBrute 2S"

G_BEGIN_DECLS

#define MB2S_TYPE_BOOK (mb2s_book_get_type ())

G_DECLARE_FINAL_TYPE (Mb2sBook, mb2s_book, MB2S, BOOK, ArBook)

G_END_DECLS
