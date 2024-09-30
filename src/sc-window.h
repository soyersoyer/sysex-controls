#pragma once

#include <adwaita.h>

G_BEGIN_DECLS

#define SC_TYPE_WINDOW (sc_window_get_type ())

G_DECLARE_FINAL_TYPE (ScWindow, sc_window, SC, WINDOW, AdwApplicationWindow)

void sc_window_register_control (ScWindow *self, uint16_t control_id, GtkWidget *widget);

G_END_DECLS

