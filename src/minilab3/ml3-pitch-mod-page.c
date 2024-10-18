#include "ml3-pitch-mod-page.h"

struct _Ml3PitchModPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml3PitchModPage, ml3_pitch_mod_page, SC_TYPE_NAVIGATION_PAGE)

static void
ml3_pitch_mod_page_class_init (Ml3PitchModPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab3/ml3-pitch-mod-page.ui");
}

static void
ml3_pitch_mod_page_init (Ml3PitchModPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
