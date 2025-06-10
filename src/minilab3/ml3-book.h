#pragma once

#include <adwaita.h>

#include "ar-book.h"
#include "sc-action-row.h"
#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define ML3_TYPE_BOOK (ml3_book_get_type ())

G_DECLARE_FINAL_TYPE (Ml3Book, ml3_book, ML3, BOOK, ArBook)

G_END_DECLS
