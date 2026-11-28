#pragma once

#include <adwaita.h>

#include "korg-book.h"

G_BEGIN_DECLS

#define NKLS_TYPE_BOOK (nkls_book_get_type ())

G_DECLARE_FINAL_TYPE (NklsBook, nkls_book, NKLS, BOOK, KorgBook)

G_END_DECLS
