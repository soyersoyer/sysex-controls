#pragma once

#include <adwaita.h>

G_BEGIN_DECLS

#define KS37_TYPE_BOOK (ks37_book_get_type ())

G_DECLARE_FINAL_TYPE (Ks37Book, ks37_book, KS37, BOOK, AdwBin)

GtkWidget * ks37_book_new (void);

G_END_DECLS

