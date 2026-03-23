#pragma once

#include <adwaita.h>

#include "korg-book.h"

G_BEGIN_DECLS

#define NK1_TYPE_BOOK (nk1_book_get_type ())

G_DECLARE_FINAL_TYPE (Nk1Book, nk1_book, NK1, BOOK, KorgBook)

G_END_DECLS
