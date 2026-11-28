#pragma once

#include <adwaita.h>

#include "korg-book.h"

G_BEGIN_DECLS

#define NKS_TYPE_BOOK (nks_book_get_type ())

G_DECLARE_FINAL_TYPE (NksBook, nks_book, NKS, BOOK, KorgBook)

G_END_DECLS
