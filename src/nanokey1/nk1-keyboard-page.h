#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NK1_TYPE_KEYBOARD_PAGE (nk1_keyboard_page_get_type ())

G_DECLARE_FINAL_TYPE (Nk1KeyboardPage, nk1_keyboard_page, NK1, KEYBOARD_PAGE, ScNavigationPage)

G_END_DECLS
