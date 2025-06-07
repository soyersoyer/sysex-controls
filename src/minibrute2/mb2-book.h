#pragma once

#include <adwaita.h>

#include "ar-book.h"

G_BEGIN_DECLS

#define MB2_TYPE_BOOK (mb2_book_get_type ())

G_DECLARE_FINAL_TYPE (Mb2Book, mb2_book, MB2, BOOK, ArBook)

G_END_DECLS
