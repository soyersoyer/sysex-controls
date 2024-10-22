#pragma once

#include <adwaita.h>

#include "ar-book.h"

#define KL2_49_MIDI_NAME "KeyLab mkII 49"
#define KL2_49_SHORT_NAME "KeyLab mkII 49"

#define KL2_61_MIDI_NAME "KeyLab mkII 61"
#define KL2_61_SHORT_NAME "KeyLab mkII 61"

#define KL2_88_MIDI_NAME "KeyLab mkII 88"
#define KL2_88_SHORT_NAME "KeyLab mkII 88"

G_BEGIN_DECLS

#define KL2_TYPE_BOOK (kl2_book_get_type ())

G_DECLARE_FINAL_TYPE (Kl2Book, kl2_book, KL2, BOOK, ArBook)

GtkWidget * kl2_book_new (snd_seq_t *seq, snd_seq_addr_t addr);

G_END_DECLS
