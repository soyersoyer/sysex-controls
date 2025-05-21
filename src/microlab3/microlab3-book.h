#pragma once

#include <adwaita.h>

#include "ar-book.h"

#define MICROLAB3_MIDI_NAME "MicroLab mk3"
#define MICROLAB3_SHORT_NAME "MicroLab3"

G_BEGIN_DECLS

#define MICROLAB3_TYPE_BOOK (microlab3_book_get_type ())

G_DECLARE_FINAL_TYPE (Microlab3Book, microlab3_book, MICROLAB3, BOOK, ArBook)

G_END_DECLS
