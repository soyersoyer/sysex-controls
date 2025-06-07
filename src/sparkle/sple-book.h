#pragma once

#include <adwaita.h>

#include "ar-book.h"

G_BEGIN_DECLS

#define SPLE_TYPE_BOOK (sple_book_get_type ())

G_DECLARE_FINAL_TYPE (SpleBook, sple_book, SPLE, BOOK, ArBook)

G_END_DECLS
