#pragma once

#include <adwaita.h>

G_BEGIN_DECLS

#define KS37_TYPE_WINDOW (ks37_window_get_type())

G_DECLARE_FINAL_TYPE (Ks37Window, ks37_window, KS37, WINDOW, AdwApplicationWindow)

void ks37_window_register_control(Ks37Window *self, uint16_t control_id, GtkWidget *widget);

G_END_DECLS

