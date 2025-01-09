#pragma once

#include <adwaita.h>

#include "ar-book.h"

#define DBI_MIDI_NAME "Arturia DrumBrute Impact"
#define DBI_SHORT_NAME "DB Impact"

G_BEGIN_DECLS

#define DBI_TYPE_BOOK (dbi_book_get_type ())

G_DECLARE_FINAL_TYPE (DbiBook, dbi_book, DBI, BOOK, ArBook)

G_END_DECLS
