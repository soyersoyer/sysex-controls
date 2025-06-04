#include "nk2-pitch-bend-page.h"

struct _Nk2PitchBendPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Nk2PitchBendPage, nk2_pitch_bend_page, SC_TYPE_NAVIGATION_PAGE)

static void
nk2_pitch_bend_page_class_init (Nk2PitchBendPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokey2/nk2-pitch-bend-page.ui");
}

static void
nk2_pitch_bend_page_init (Nk2PitchBendPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
