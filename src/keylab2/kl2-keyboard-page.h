#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL2_TYPE_KEYBOARD_PAGE (kl2_keyboard_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl2KeyboardPage, kl2_keyboard_page, KL2, KEYBOARD_PAGE, ScNavigationPage)

G_END_DECLS
