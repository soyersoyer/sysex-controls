#include "microlab-pitch-page.h"

struct _MicrolabPitchPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (MicrolabPitchPage, microlab_pitch_page, SC_TYPE_NAVIGATION_PAGE)

static void
microlab_pitch_page_class_init (MicrolabPitchPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/microlab/microlab-pitch-page.ui");
}

static void
microlab_pitch_page_init (MicrolabPitchPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
