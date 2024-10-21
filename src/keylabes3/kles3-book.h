#pragma once

#include <adwaita.h>

#include "ar-book.h"

#define KLES3_49_MIDI_NAME "KL Essential 49 mk3"
#define KLES3_49_SHORT_NAME "KeyLab ES 49 mk3"

#define KLES3_61_MIDI_NAME "KL Essential 61 mk3"
#define KLES3_61_SHORT_NAME "KeyLab ES 61 mk3"

#define KLES3_88_MIDI_NAME "KL Essential 88 mk3"
#define KLES3_88_SHORT_NAME "KeyLab ES 88 mk3"

G_BEGIN_DECLS

#define KLES3_TYPE_BOOK (kles3_book_get_type ())

G_DECLARE_FINAL_TYPE (Kles3Book, kles3_book, KLES3, BOOK, ArBook)

GtkWidget * kles3_book_new (snd_seq_t *seq, snd_seq_addr_t addr);

G_END_DECLS
