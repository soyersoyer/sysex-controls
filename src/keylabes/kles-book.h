#pragma once

#include <adwaita.h>

#include "ar-book.h"

G_BEGIN_DECLS

#define KLES_TYPE_BOOK (kles_book_get_type ())

G_DECLARE_FINAL_TYPE (KlesBook, kles_book, KLES, BOOK, ArBook)

G_END_DECLS
