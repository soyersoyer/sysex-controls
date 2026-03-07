#pragma once

#include <adwaita.h>

#include "korg-book.h"

G_BEGIN_DECLS

#define NKL1_TYPE_BOOK (nkl1_book_get_type ())

G_DECLARE_FINAL_TYPE (Nkl1Book, nkl1_book, NKL1, BOOK, KorgBook)

G_END_DECLS
