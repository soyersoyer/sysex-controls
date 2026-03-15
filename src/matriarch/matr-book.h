#pragma once

#include <adwaita.h>

#include "ar-book.h"

G_BEGIN_DECLS

#define MATR_TYPE_BOOK (matr_book_get_type ())

G_DECLARE_FINAL_TYPE (MatrBook, matr_book, MATR, BOOK, ArBook)

G_END_DECLS
