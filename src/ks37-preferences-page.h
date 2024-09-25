#pragma once

#include <adwaita.h>

G_BEGIN_DECLS

#define KS37_TYPE_PREFERENCES_PAGE (ks37_preferences_page_get_type())

G_DECLARE_DERIVABLE_TYPE (Ks37PreferencesPage, ks37_preferences_page, KS37, PREFERENCES_PAGE, AdwPreferencesPage)

struct _Ks37PreferencesPageClass
{
	AdwPreferencesPageClass parent_class;
};

uint8_t ks37_preferences_page_get_midi_id_offset (Ks37PreferencesPage *self);

G_END_DECLS

