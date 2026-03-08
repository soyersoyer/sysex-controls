#pragma once

#include <adwaita.h>

#include "korg-book.h"

G_BEGIN_DECLS

#define NP1_TYPE_BOOK (np1_book_get_type ())

G_DECLARE_FINAL_TYPE (Np1Book, np1_book, NP1, BOOK, KorgBook)

G_END_DECLS
