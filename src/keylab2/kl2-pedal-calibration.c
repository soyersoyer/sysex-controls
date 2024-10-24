#include "kl2-pedal-calibration.h"

struct _Kl2PedalCalibration
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl2PedalCalibration, kl2_pedal_calibration, SC_TYPE_PREFERENCES_GROUP)

static void
kl2_pedal_calibration_class_init (Kl2PedalCalibrationClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab2/kl2-pedal-calibration.ui");
}

static void
kl2_pedal_calibration_init (Kl2PedalCalibration *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
