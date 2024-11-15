#pragma once

#include <adwaita.h>

G_BEGIN_DECLS

#define AR2_TYPE_USER_SCALE (ar2_user_scale_get_type ())

G_DECLARE_FINAL_TYPE (Ar2UserScale, ar2_user_scale, AR2, USER_SCALE, GtkBox)

uint8_t ar2_user_scale_get_part (Ar2UserScale *self);
void ar2_user_scale_set_part (Ar2UserScale *self, uint8_t part);
uint8_t ar2_user_scale_get_value (Ar2UserScale *self);
void ar2_user_scale_set_value (Ar2UserScale *self, uint8_t value);
void ar2_user_scale_toggle_cb (Ar2UserScale *self, GtkToggleButton *btn);

G_END_DECLS
