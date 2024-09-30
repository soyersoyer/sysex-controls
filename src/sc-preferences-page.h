#pragma once

#include <adwaita.h>

G_BEGIN_DECLS

#define SC_TYPE_PREFERENCES_PAGE (sc_preferences_page_get_type ())

G_DECLARE_DERIVABLE_TYPE (ScPreferencesPage, sc_preferences_page, SC, PREFERENCES_PAGE, AdwPreferencesPage)

struct _ScPreferencesPageClass
{
  AdwPreferencesPageClass parent_class;
};

uint16_t sc_preferences_page_get_control_id_offset (ScPreferencesPage *self);

G_END_DECLS

