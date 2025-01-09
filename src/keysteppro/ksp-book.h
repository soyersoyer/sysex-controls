#pragma once

#include <adwaita.h>

#include "ar-book.h"

#define KSP_MIDI_NAME "KeyStep Pro"
#define KSP_SHORT_NAME "KeyStep Pro"

G_BEGIN_DECLS

#define KSP_TYPE_BOOK (ksp_book_get_type ())

G_DECLARE_FINAL_TYPE (KspBook, ksp_book, KSP, BOOK, ArBook)

G_END_DECLS
