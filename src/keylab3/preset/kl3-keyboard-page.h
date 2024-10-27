#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL3_TYPE_KEYBOARD_PAGE (kl3_keyboard_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl3KeyboardPage, kl3_keyboard_page, KL3, KEYBOARD_PAGE, ScNavigationPage)

G_END_DECLS
