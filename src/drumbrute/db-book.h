#pragma once

#include <adwaita.h>

#include "ar-book.h"

#define DB_MIDI_NAME "Arturia DrumBrute"
#define DB_SHORT_NAME "DrumBrute"

G_BEGIN_DECLS

#define DB_TYPE_BOOK (db_book_get_type ())

G_DECLARE_FINAL_TYPE (DbBook, db_book, DB, BOOK, ArBook)

GtkWidget * db_book_new (void);

G_END_DECLS
