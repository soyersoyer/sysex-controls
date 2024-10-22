#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KLES_TYPE_KEYBOARD_PAGE (kles_keyboard_page_get_type ())

G_DECLARE_FINAL_TYPE (KlesKeyboardPage, kles_keyboard_page, KLES, KEYBOARD_PAGE, ScNavigationPage)

G_END_DECLS
