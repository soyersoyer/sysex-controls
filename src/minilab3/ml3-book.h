#pragma once

#include <adwaita.h>

#include "sc-arturia-book.h"

#define ML3_MIDI_NAME "Minilab3"
#define ML3_SHORT_NAME "MiniLab 3"

G_BEGIN_DECLS

#define ML3_TYPE_BOOK (ml3_book_get_type ())

G_DECLARE_FINAL_TYPE (Ml3Book, ml3_book, ML3, BOOK, ScArturiaBook)

GtkWidget * ml3_book_new (snd_seq_t *seq, snd_seq_addr_t addr);

G_END_DECLS
