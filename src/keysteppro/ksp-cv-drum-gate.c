#include "ksp-cv-drum-gate.h"

struct _KspCvDrumGate
{
  ScComboRow parent_instance;
};

G_DEFINE_FINAL_TYPE (KspCvDrumGate, ksp_cv_drum_gate, SC_TYPE_COMBO_ROW)

static void
ksp_cv_drum_gate_class_init (KspCvDrumGateClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keysteppro/ksp-cv-drum-gate.ui");
}

static void
ksp_cv_drum_gate_init (KspCvDrumGate *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
