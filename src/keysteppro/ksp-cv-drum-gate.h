#pragma once

#include <adwaita.h>

#include "sc-combo-row.h"

G_BEGIN_DECLS

#define KSP_TYPE_CV_DRUM_GATE (ksp_cv_drum_gate_get_type ())

G_DECLARE_FINAL_TYPE (KspCvDrumGate, ksp_cv_drum_gate, KSP, CV_DRUM_GATE, ScComboRow)

G_END_DECLS
