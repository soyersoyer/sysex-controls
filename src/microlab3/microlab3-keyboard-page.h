#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define MICROLAB3_TYPE_KEYBOARD_PAGE (microlab3_keyboard_page_get_type ())

G_DECLARE_FINAL_TYPE (Microlab3KeyboardPage, microlab3_keyboard_page, MICROLAB3, KEYBOARD_PAGE, ScNavigationPage)

G_END_DECLS
