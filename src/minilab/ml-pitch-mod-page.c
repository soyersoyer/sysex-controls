#include "ml-pitch-mod-page.h"

struct _MlPitchModPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (MlPitchModPage, ml_pitch_mod_page, SC_TYPE_NAVIGATION_PAGE)

static void
ml_pitch_mod_page_class_init (MlPitchModPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab/ml-pitch-mod-page.ui");
}

static void
ml_pitch_mod_page_init (MlPitchModPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
