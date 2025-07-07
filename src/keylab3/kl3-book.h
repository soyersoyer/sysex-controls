#pragma once

#include <adwaita.h>

#include "ar-book.h"

G_BEGIN_DECLS

#define KL3_TYPE_BOOK (kl3_book_get_type ())

G_DECLARE_FINAL_TYPE (Kl3Book, kl3_book, KL3, BOOK, ArBook)

G_END_DECLS
