#include "microlab3-pitch-mod-page.h"

struct _Microlab3PitchModPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Microlab3PitchModPage, microlab3_pitch_mod_page, SC_TYPE_NAVIGATION_PAGE)

static void
microlab3_pitch_mod_page_class_init (Microlab3PitchModPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/microlab3/microlab3-pitch-mod-page.ui");
}

static void
microlab3_pitch_mod_page_init (Microlab3PitchModPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
