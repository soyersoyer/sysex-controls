#pragma once

#include <adwaita.h>

#include "ar-book.h"

G_BEGIN_DECLS

#define BSP_TYPE_BOOK (bsp_book_get_type ())

G_DECLARE_FINAL_TYPE (BspBook, bsp_book, BSP, BOOK, ArBook)

G_END_DECLS
