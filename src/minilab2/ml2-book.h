#pragma once

#include <adwaita.h>

#include "sc-arturia-book.h"

#define ML2_MIDI_NAME "Arturia MiniLab mkII"
#define ML2_SHORT_NAME "MiniLab mkII"

G_BEGIN_DECLS

#define ML2_TYPE_BOOK (ml2_book_get_type ())

G_DECLARE_FINAL_TYPE (Ml2Book, ml2_book, ML2, BOOK, ScArturiaBook)

GtkWidget * ml2_book_new (snd_seq_t *seq, snd_seq_addr_t *addr);
G_END_DECLS

