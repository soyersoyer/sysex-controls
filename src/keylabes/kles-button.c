#include "kles-button.h"

struct _KlesButton
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (KlesButton, kles_button, SC_TYPE_PREFERENCES_GROUP)

static void
kles_button_class_init (KlesButtonClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes/kles-button.ui");
}

static void
kles_button_init (KlesButton *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
