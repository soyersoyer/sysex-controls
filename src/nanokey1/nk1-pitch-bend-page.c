#include "nk1-pitch-bend-page.h"

struct _Nk1PitchBendPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Nk1PitchBendPage, nk1_pitch_bend_page, SC_TYPE_NAVIGATION_PAGE)

static void
nk1_pitch_bend_page_class_init (Nk1PitchBendPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokey1/nk1-pitch-bend-page.ui");
}

static void
nk1_pitch_bend_page_init (Nk1PitchBendPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
