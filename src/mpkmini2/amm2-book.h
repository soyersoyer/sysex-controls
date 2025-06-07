#pragma once

#include <adwaita.h>

#include "ak-book.h"

G_BEGIN_DECLS

#define AMM2_TYPE_BOOK (amm2_book_get_type ())

G_DECLARE_FINAL_TYPE (Amm2Book, amm2_book, AMM2, BOOK, AkBook)

G_END_DECLS
