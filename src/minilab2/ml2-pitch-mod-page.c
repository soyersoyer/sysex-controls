#include "ml2-pitch-mod-page.h"

struct _Ml2PitchModPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml2PitchModPage, ml2_pitch_mod_page, SC_TYPE_NAVIGATION_PAGE)

static void
ml2_pitch_mod_page_class_init (Ml2PitchModPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab2/ml2-pitch-mod-page.ui");
}

static void
ml2_pitch_mod_page_init (Ml2PitchModPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
