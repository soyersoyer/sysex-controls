#pragma once

#include <adwaita.h>

#include "ar-book.h"

G_BEGIN_DECLS

#define KL2_TYPE_BOOK (kl2_book_get_type ())

G_DECLARE_FINAL_TYPE (Kl2Book, kl2_book, KL2, BOOK, ArBook)

G_END_DECLS
