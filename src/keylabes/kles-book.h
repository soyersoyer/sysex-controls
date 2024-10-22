#pragma once

#include <adwaita.h>

#include "ar-book.h"

#define KLES_49_MIDI_NAME "Arturia KeyLab Essential 49"
#define KLES_49_SHORT_NAME "KeyLab ES 49"

#define KLES_61_MIDI_NAME "Arturia KeyLab Essential 61"
#define KLES_61_SHORT_NAME "KeyLab ES 61"

#define KLES_88_MIDI_NAME "Arturia KeyLab Essential 88"
#define KLES_88_SHORT_NAME "KeyLab ES 88"

G_BEGIN_DECLS

#define KLES_TYPE_BOOK (kles_book_get_type ())

G_DECLARE_FINAL_TYPE (KlesBook, kles_book, KLES, BOOK, ArBook)

GtkWidget * kles_book_new (snd_seq_t *seq, snd_seq_addr_t addr);

G_END_DECLS
