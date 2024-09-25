#pragma once

#include <adwaita.h>

G_BEGIN_DECLS

#define KS37_TYPE_PREFERENCES_GROUP (ks37_preferences_group_get_type())

G_DECLARE_DERIVABLE_TYPE (Ks37PreferencesGroup, ks37_preferences_group, KS37, PREFERENCES_GROUP, AdwPreferencesGroup)

struct _Ks37PreferencesGroupClass
{
	AdwPreferencesGroupClass parent_class;
};

uint8_t ks37_preferences_group_get_midi_id_offset (Ks37PreferencesGroup *self);

G_END_DECLS

