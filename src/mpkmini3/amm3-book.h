#pragma once

#include <adwaita.h>

#include "ak-book.h"

G_BEGIN_DECLS

#define AMM3_TYPE_BOOK (amm3_book_get_type ())

G_DECLARE_FINAL_TYPE (Amm3Book, amm3_book, AMM3, BOOK, AkBook)

G_END_DECLS
