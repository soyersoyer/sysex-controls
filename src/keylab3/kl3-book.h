#pragma once

#include <adwaita.h>

#include "ar-book.h"

#define KL3_49_MIDI_NAME "KeyLab 49 mk3"
#define KL3_49_SHORT_NAME "KeyLab 49 mk3"

#define KL3_61_MIDI_NAME "KeyLab 61 mk3"
#define KL3_61_SHORT_NAME "KeyLab 61 mk3"

#define KL3_88_MIDI_NAME "KeyLab 88 mk3"
#define KL3_88_SHORT_NAME "KeyLab 88 mk3"

G_BEGIN_DECLS

#define KL3_TYPE_BOOK (kl3_book_get_type ())

G_DECLARE_FINAL_TYPE (Kl3Book, kl3_book, KL3, BOOK, ArBook)

GtkWidget * kl3_book_new (void);

G_END_DECLS
