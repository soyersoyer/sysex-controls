#pragma once

#include <adwaita.h>

#include "ar-book.h"

#define BSP_MIDI_NAME "Arturia BeatStep Pro"
#define BSP_SHORT_NAME "BS Pro"

G_BEGIN_DECLS

#define BSP_TYPE_BOOK (bsp_book_get_type ())

G_DECLARE_FINAL_TYPE (BspBook, bsp_book, BSP, BOOK, ArBook)

GtkWidget * bsp_book_new (void);

G_END_DECLS
