#pragma once

#include <adwaita.h>

#include "ar-book.h"

#define KS32_MIDI_NAME "Arturia KeyStep 32"
#define KS32_SHORT_NAME "KeyStep 32"

G_BEGIN_DECLS

#define KS32_TYPE_BOOK (ks32_book_get_type ())

G_DECLARE_FINAL_TYPE (Ks32Book, ks32_book, KS32, BOOK, ArBook)

GtkWidget * ks32_book_new (snd_seq_t *seq, snd_seq_addr_t addr);

G_END_DECLS
