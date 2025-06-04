#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NK2_TYPE_KEYBOARD_PAGE (nk2_keyboard_page_get_type ())

G_DECLARE_FINAL_TYPE (Nk2KeyboardPage, nk2_keyboard_page, NK2, KEYBOARD_PAGE, ScNavigationPage)

G_END_DECLS
