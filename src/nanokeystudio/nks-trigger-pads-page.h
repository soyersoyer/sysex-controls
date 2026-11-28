#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define NKS_TYPE_TRIGGER_PADS_PAGE (nks_trigger_pads_page_get_type ())

G_DECLARE_FINAL_TYPE (NksTriggerPadsPage, nks_trigger_pads_page, NKS, TRIGGER_PADS_PAGE, ScNavigationPage)

G_END_DECLS
