#include "bsp-drum-group.h"

struct _BspDrumGroup
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (BspDrumGroup, bsp_drum_group, SC_TYPE_PREFERENCES_GROUP)

static void
bsp_drum_group_class_init (BspDrumGroupClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatsteppro/bsp-drum-group.ui");
}

static void
bsp_drum_group_init (BspDrumGroup *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
