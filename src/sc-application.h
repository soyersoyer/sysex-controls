#pragma once

#include <adwaita.h>

G_BEGIN_DECLS

#define SC_TYPE_APPLICATION (sc_application_get_type ())

G_DECLARE_FINAL_TYPE (ScApplication, sc_application, SC, APPLICATION, AdwApplication)

ScApplication *sc_application_new (const char        *application_id,
                                   GApplicationFlags  flags);

G_END_DECLS
