#include "kl2-cv-mod.h"

struct _Kl2CvMod
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl2CvMod, kl2_cv_mod, SC_TYPE_PREFERENCES_GROUP)

static void
kl2_cv_mod_class_init (Kl2CvModClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab2/kl2-cv-mod.ui");
}

static void
kl2_cv_mod_init (Kl2CvMod *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
