#pragma once

#include <adwaita.h>

#include "ar-book.h"

G_BEGIN_DECLS

#define DBI_TYPE_BOOK (dbi_book_get_type ())

G_DECLARE_FINAL_TYPE (DbiBook, dbi_book, DBI, BOOK, ArBook)

G_END_DECLS
