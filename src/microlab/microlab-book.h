#pragma once

#include <adwaita.h>

#include "sc-arturia-book.h"

#define MICROLAB_MIDI_NAME "Arturia MicroLab"
#define MICROLAB_SHORT_NAME "MicroLab"

G_BEGIN_DECLS

#define MICROLAB_TYPE_BOOK (microlab_book_get_type ())

G_DECLARE_FINAL_TYPE (MicrolabBook, microlab_book, MICROLAB, BOOK, ScArturiaBook)

GtkWidget * microlab_book_new (snd_seq_t *seq, snd_seq_addr_t addr);

G_END_DECLS
