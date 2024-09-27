#pragma once

#include <adwaita.h>

#include "ks37-preferences-page.h"

G_BEGIN_DECLS

#define KS37_TYPE_PAGE_SEQUENCE (ks37_page_sequence_get_type())

G_DECLARE_FINAL_TYPE (Ks37PageSequence, ks37_page_sequence, KS37, PAGE_SEQUENCE, Ks37PreferencesPage)

G_END_DECLS

