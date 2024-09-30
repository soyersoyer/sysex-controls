#pragma once

#include <adwaita.h>

G_BEGIN_DECLS

#define SC_TYPE_PREFERENCES_GROUP (sc_preferences_group_get_type ())

G_DECLARE_DERIVABLE_TYPE (ScPreferencesGroup, sc_preferences_group, SC, PREFERENCES_GROUP, AdwPreferencesGroup)

struct _ScPreferencesGroupClass
{
  AdwPreferencesGroupClass parent_class;
};

uint16_t sc_preferences_group_get_control_id_offset (ScPreferencesGroup *self);

G_END_DECLS

