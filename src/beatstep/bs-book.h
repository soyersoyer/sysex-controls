#pragma once

#include <adwaita.h>

#include "ar-book.h"

G_BEGIN_DECLS

#define BS_TYPE_BOOK (bs_book_get_type ())

G_DECLARE_FINAL_TYPE (BsBook, bs_book, BS, BOOK, ArBook)

G_END_DECLS
