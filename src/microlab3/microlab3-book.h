#pragma once

#include <adwaita.h>

#include "ar-book.h"

G_BEGIN_DECLS

#define MICROLAB3_TYPE_BOOK (microlab3_book_get_type ())

G_DECLARE_FINAL_TYPE (Microlab3Book, microlab3_book, MICROLAB3, BOOK, ArBook)

G_END_DECLS
