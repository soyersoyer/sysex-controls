#pragma once

#include <adwaita.h>

#include "ar-book.h"

G_BEGIN_DECLS

#define MICROLAB_TYPE_BOOK (microlab_book_get_type ())

G_DECLARE_FINAL_TYPE (MicrolabBook, microlab_book, MICROLAB, BOOK, ArBook)

G_END_DECLS
