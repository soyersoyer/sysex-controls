#pragma once

#include <adwaita.h>

G_BEGIN_DECLS

#define SC_TYPE_WINDOW (sc_window_get_type ())

G_DECLARE_FINAL_TYPE (ScWindow, sc_window, SC, WINDOW, AdwApplicationWindow)

void __attribute__ ((format (gnu_printf, 2, 3))) sc_io_problem (ScWindow *self, const char *format, ...);
void sc_window_load_page (ScWindow *self, const char* name);

G_END_DECLS
