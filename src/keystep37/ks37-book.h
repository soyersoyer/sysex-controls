#pragma once

#include <adwaita.h>

#include "ar-book.h"

#define KS37_MIDI_NAME "Arturia KeyStep 37"
#define KS37_SHORT_NAME "KeyStep 37"

G_BEGIN_DECLS

#define KS37_TYPE_BOOK (ks37_book_get_type ())

G_DECLARE_FINAL_TYPE (Ks37Book, ks37_book, KS37, BOOK, ArBook)

GtkWidget * ks37_book_new (void);

G_END_DECLS
