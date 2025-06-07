#pragma once

#include <adwaita.h>

#include "korg-book.h"

G_BEGIN_DECLS

#define NKL2_TYPE_BOOK (nkl2_book_get_type ())

G_DECLARE_FINAL_TYPE (Nkl2Book, nkl2_book, NKL2, BOOK, KorgBook)

G_END_DECLS
