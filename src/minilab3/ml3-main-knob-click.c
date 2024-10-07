#include "ml3-main-knob-click.h"

struct _Ml3MainKnobClick
{
  ScPreferencesGroup parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml3MainKnobClick, ml3_main_knob_click, SC_TYPE_PREFERENCES_GROUP)

static void
ml3_main_knob_click_class_init (Ml3MainKnobClickClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab3/ml3-main-knob-click.ui");
}

static void
ml3_main_knob_click_init (Ml3MainKnobClick *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
