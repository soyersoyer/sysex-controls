#pragma once

#include <adwaita.h>

#include "ak-book.h"

G_BEGIN_DECLS

#define AMM_TYPE_BOOK (amm_book_get_type ())

G_DECLARE_FINAL_TYPE (AmmBook, amm_book, AMM, BOOK, AkBook)

G_END_DECLS
