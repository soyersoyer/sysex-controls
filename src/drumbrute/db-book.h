#pragma once

#include <adwaita.h>

#include "ar-book.h"

G_BEGIN_DECLS

#define DB_TYPE_BOOK (db_book_get_type ())

G_DECLARE_FINAL_TYPE (DbBook, db_book, DB, BOOK, ArBook)

G_END_DECLS
