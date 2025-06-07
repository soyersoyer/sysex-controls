#pragma once

#include <adwaita.h>

#include "ar-book.h"

G_BEGIN_DECLS

#define KS32_TYPE_BOOK (ks32_book_get_type ())

G_DECLARE_FINAL_TYPE (Ks32Book, ks32_book, KS32, BOOK, ArBook)

G_END_DECLS
