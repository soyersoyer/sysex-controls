#pragma once

#include <adwaita.h>

#include "ar-book.h"

G_BEGIN_DECLS

#define KLES3_TYPE_BOOK (kles3_book_get_type ())

G_DECLARE_FINAL_TYPE (Kles3Book, kles3_book, KLES3, BOOK, ArBook)

G_END_DECLS
