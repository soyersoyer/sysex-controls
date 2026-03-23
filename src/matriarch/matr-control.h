#pragma once

#include <adwaita.h>

G_BEGIN_DECLS

#define MATR_TYPE_CONTROL (matr_control_get_type ())

G_DECLARE_FINAL_TYPE (MatrControl, matr_control, MATR, CONTROL, AdwBin)

uint8_t matr_control_get_id (MatrControl *self);

G_END_DECLS
