#pragma once

#include <adwaita.h>

#include "ar-book.h"
#include "sc-navigation-page.h"
#include "sc-action-row.h"

G_BEGIN_DECLS

#define KLES3_TYPE_BOOK (kles3_book_get_type ())

G_DECLARE_FINAL_TYPE (Kles3Book, kles3_book, KLES3, BOOK, ArBook)

void sc_action_kles3_preset_nav_push (ScActionRow *row, ScNavigationPage *page);

G_END_DECLS
