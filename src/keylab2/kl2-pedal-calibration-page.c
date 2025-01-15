#include "kl2-pedal-calibration-page.h"

struct _Kl2PedalCalibrationPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl2PedalCalibrationPage, kl2_pedal_calibration_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl2_pedal_calibration_page_class_init (Kl2PedalCalibrationPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab2/kl2-pedal-calibration-page.ui");
}

static void
kl2_pedal_calibration_page_init (Kl2PedalCalibrationPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
