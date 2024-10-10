#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define KS37_TYPE_SEQUENCE_PAGE (ks37_sequence_page_get_type ())

G_DECLARE_FINAL_TYPE (Ks37SequencePage, ks37_sequence_page, KS37, SEQUENCE_PAGE, ScNavigationPage)

G_END_DECLS
