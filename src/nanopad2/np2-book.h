#pragma once

#include <adwaita.h>

#include "korg-book.h"

G_BEGIN_DECLS

#define NP2_TYPE_BOOK (np2_book_get_type ())

G_DECLARE_FINAL_TYPE (Np2Book, np2_book, NP2, BOOK, KorgBook)

G_END_DECLS
