#pragma once

#include <adwaita.h>

#include "ar-book.h"

G_BEGIN_DECLS

#define KL25_TYPE_BOOK (kl25_book_get_type ())

G_DECLARE_FINAL_TYPE (Kl25Book, kl25_book, KL25, BOOK, ArBook)

G_END_DECLS
