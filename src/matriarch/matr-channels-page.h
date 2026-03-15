#pragma once

#include "ar-book.h"

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define MATR_TYPE_CHANNELS_PAGE (matr_channels_page_get_type ())

G_DECLARE_FINAL_TYPE (MatrChannelsPage, matr_channels_page, MATR, CHANNELS, ScNavigationPage)

G_END_DECLS
