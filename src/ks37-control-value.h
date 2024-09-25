#pragma once

#include <adwaita.h>

G_BEGIN_DECLS

#define KS37_TYPE_CONTROL_VALUE (ks37_control_value_get_type())

G_DECLARE_FINAL_TYPE (Ks37ControlValue, ks37_control_value, KS37, CONTROL_VALUE, GObject)

Ks37ControlValue* ks37_control_value_new(uint8_t value, const char *name);
int ks37_control_value_get_value (Ks37ControlValue *self);
const char* ks37_control_value_get_name (Ks37ControlValue *self);

#define KS37_TYPE_CONTROL_VALUE_LIST (ks37_control_value_list_get_type ())

G_DECLARE_FINAL_TYPE (Ks37ControlValueList, ks37_control_value_list, KS37, CONTROL_VALUE_LIST, GObject)


Ks37ControlValueList * ks37_control_value_list_new (const Ks37ControlValue * const *cvs);
void ks37_control_value_list_append (Ks37ControlValueList *self, const Ks37ControlValue *cv);
void ks37_control_value_list_take (Ks37ControlValueList *self, char *string);
void ks37_control_value_list_remove (Ks37ControlValueList *self, guint position);
void ks37_control_value_list_splice (Ks37ControlValueList *self, guint position,
				     guint n_removals, const Ks37ControlValue * const *additions);
const Ks37ControlValue * ks37_control_value_list_get_cv (Ks37ControlValueList *self, guint position);

G_END_DECLS

