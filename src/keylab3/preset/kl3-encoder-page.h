#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KL3_TYPE_ENCODER_PAGE (kl3_encoder_page_get_type ())

G_DECLARE_FINAL_TYPE (Kl3EncoderPage, kl3_encoder_page, KL3, ENCODER_PAGE, ScNavigationPage)

G_END_DECLS
