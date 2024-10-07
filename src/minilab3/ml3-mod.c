#include "ml3-mod.h"

struct _Ml3Mod
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml3Mod, ml3_mod, SC_TYPE_PREFERENCES_GROUP)

static void
ml3_mod_class_init (Ml3ModClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab3/ml3-mod.ui");
}

static void
ml3_mod_init (Ml3Mod *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
