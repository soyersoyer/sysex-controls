#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKS_TYPE_TRIGGER_PAD_PAGE (nks_trigger_pad_page_get_type ())

G_DECLARE_FINAL_TYPE (NksTriggerPadPage, nks_trigger_pad_page, NKS, TRIGGER_PAD_PAGE, ScNavigationPage)

G_END_DECLS
