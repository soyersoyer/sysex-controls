#pragma once

#include <adwaita.h>

#include "ar-book.h"

G_BEGIN_DECLS

#define KL88_TYPE_BOOK (kl88_book_get_type ())

G_DECLARE_FINAL_TYPE (Kl88Book, kl88_book, KL88, BOOK, ArBook)

G_END_DECLS
