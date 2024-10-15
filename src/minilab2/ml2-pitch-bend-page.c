#include "ml2-pitch-bend-page.h"

struct _Ml2PitchBendPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml2PitchBendPage, ml2_pitch_bend_page, SC_TYPE_NAVIGATION_PAGE)

static void
ml2_pitch_bend_page_class_init (Ml2PitchBendPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab2/ml2-pitch-bend-page.ui");
}

static void
ml2_pitch_bend_page_init (Ml2PitchBendPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
