#include "kl3-pitch-mod-page.h"

struct _Kl3PitchModPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl3PitchModPage, kl3_pitch_mod_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl3_pitch_mod_page_class_init (Kl3PitchModPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab3/preset/kl3-pitch-mod-page.ui");
}

static void
kl3_pitch_mod_page_init (Kl3PitchModPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
