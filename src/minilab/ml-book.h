#pragma once

#include <adwaita.h>

#include "ar-book.h"

#define ML_MIDI_NAME "Arturia MINILAB"
#define ML_SHORT_NAME "MiniLab"

G_BEGIN_DECLS

#define ML_TYPE_BOOK (ml_book_get_type ())

G_DECLARE_FINAL_TYPE (MlBook, ml_book, ML, BOOK, ArBook)

G_END_DECLS
