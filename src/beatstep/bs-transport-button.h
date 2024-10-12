#pragma once

#include <adwaita.h>

#include "sc-preferences-group.h"

G_BEGIN_DECLS

#define BS_TYPE_TRANSPORT_BUTTON (bs_transport_button_get_type ())

G_DECLARE_FINAL_TYPE (BsTransportButton, bs_transport_button, BS, TRANSPORT_BUTTON, ScPreferencesGroup)

G_END_DECLS
