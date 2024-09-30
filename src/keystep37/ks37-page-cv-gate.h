#pragma once

#include <adwaita.h>

#include "sc-preferences-page.h"

G_BEGIN_DECLS

#define KS37_TYPE_PAGE_CV_GATE (ks37_page_cv_gate_get_type ())

G_DECLARE_FINAL_TYPE (Ks37PageCvGate, ks37_page_cv_gate, KS37, PAGE_CV_GATE, ScPreferencesPage)

G_END_DECLS
