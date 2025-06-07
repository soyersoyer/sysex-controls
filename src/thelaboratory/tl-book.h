#pragma once

#include <adwaita.h>

#include "ar-book.h"

G_BEGIN_DECLS

#define TL_TYPE_BOOK (tl_book_get_type ())

G_DECLARE_FINAL_TYPE (TlBook, tl_book, TL, BOOK, ArBook)

G_END_DECLS
