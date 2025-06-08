#pragma once

#include <adwaita.h>

#include "ar-book.h"

G_BEGIN_DECLS

#define ML2_TYPE_BOOK (ml2_book_get_type ())

G_DECLARE_FINAL_TYPE (Ml2Book, ml2_book, ML2, BOOK, ArBook)

G_END_DECLS
