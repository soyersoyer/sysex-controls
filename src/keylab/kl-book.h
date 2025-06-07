#pragma once

#include <adwaita.h>

#include "ar-book.h"

G_BEGIN_DECLS

#define KL_TYPE_BOOK (kl_book_get_type ())

G_DECLARE_FINAL_TYPE (KlBook, kl_book, KL, BOOK, ArBook)

G_END_DECLS
