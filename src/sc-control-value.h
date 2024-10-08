#pragma once

#include <adwaita.h>

G_BEGIN_DECLS

#define SC_TYPE_CONTROL_VALUE (sc_control_value_get_type ())

G_DECLARE_FINAL_TYPE (ScControlValue, sc_control_value, SC, CONTROL_VALUE, GObject)

ScControlValue* sc_control_value_new (uint8_t value, const char *name);
int sc_control_value_get_value (ScControlValue *self);
const char* sc_control_value_get_name (ScControlValue *self);
gboolean cv_in (GObject *object, ScControlValue* value, GVariant* variant);
gboolean cv_in_2 (GObject *object, ScControlValue* value, GVariant* variant, ScControlValue* value2, GVariant* variant2);

#define SC_TYPE_CONTROL_VALUE_LIST (sc_control_value_list_get_type ())

G_DECLARE_FINAL_TYPE (ScControlValueList, sc_control_value_list, SC, CONTROL_VALUE_LIST, GObject)


ScControlValueList * sc_control_value_list_new (const ScControlValue * const *cvs);
void sc_control_value_list_append (ScControlValueList *self, const ScControlValue *cv);
void sc_control_value_list_take (ScControlValueList *self, char *string);
void sc_control_value_list_remove (ScControlValueList *self, guint position);
void sc_control_value_list_splice (ScControlValueList *self, guint position,
			           guint n_removals, const ScControlValue * const *additions);
const ScControlValue * sc_control_value_list_get_cv (ScControlValueList *self, guint position);

G_END_DECLS
