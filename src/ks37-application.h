#pragma once

#include <adwaita.h>

G_BEGIN_DECLS

#define KS37_TYPE_APPLICATION (ks37_application_get_type())

G_DECLARE_FINAL_TYPE (Ks37Application, ks37_application, KS37, APPLICATION, AdwApplication)

Ks37Application *ks37_application_new (const char        *application_id,
                                       GApplicationFlags  flags);

G_END_DECLS

