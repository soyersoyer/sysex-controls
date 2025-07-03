#pragma once

#include <adwaita.h>

#include "ak-book.h"

G_BEGIN_DECLS

#define MPD218_TYPE_BOOK (mpd218_book_get_type ())

G_DECLARE_FINAL_TYPE (Mpd218Book, mpd218_book, MPD218, BOOK, AkBook)

G_END_DECLS
