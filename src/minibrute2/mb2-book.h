#pragma once

#include <adwaita.h>

#include "ar-book.h"

#define MB2_MIDI_NAME "Arturia MiniBrute 2"
#define MB2_SHORT_NAME "MiniBrute 2"

G_BEGIN_DECLS

#define MB2_TYPE_BOOK (mb2_book_get_type ())

G_DECLARE_FINAL_TYPE (Mb2Book, mb2_book, MB2, BOOK, ArBook)

GtkWidget * mb2_book_new (void);

G_END_DECLS
