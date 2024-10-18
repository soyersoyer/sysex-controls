#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define MICROLAB_TYPE_KEYBOARD_PAGE (microlab_keyboard_page_get_type ())

G_DECLARE_FINAL_TYPE (MicrolabKeyboardPage, microlab_keyboard_page, MICROLAB, KEYBOARD_PAGE, ScNavigationPage)

G_END_DECLS
