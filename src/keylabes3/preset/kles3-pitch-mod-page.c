#include "kles3-pitch-mod-page.h"

struct _Kles3PitchModPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kles3PitchModPage, kles3_pitch_mod_page, SC_TYPE_NAVIGATION_PAGE)

static void
kles3_pitch_mod_page_class_init (Kles3PitchModPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes3/preset/kles3-pitch-mod-page.ui");
}

static void
kles3_pitch_mod_page_init (Kles3PitchModPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
