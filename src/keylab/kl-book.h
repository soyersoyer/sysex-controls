#pragma once

#include <adwaita.h>

#include "ar-book.h"

#define KL49_MIDI_NAME "KeyLab 49"
#define KL49_SHORT_NAME "KeyLab 49"

#define KL61_MIDI_NAME "KeyLab 61"
#define KL61_SHORT_NAME "KeyLab 61"

G_BEGIN_DECLS

#define KL_TYPE_BOOK (kl_book_get_type ())

G_DECLARE_FINAL_TYPE (KlBook, kl_book, KL, BOOK, ArBook)

G_END_DECLS
