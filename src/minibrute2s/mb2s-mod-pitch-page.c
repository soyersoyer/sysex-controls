#include "mb2s-mod-pitch-page.h"

struct _Mb2sModPitchPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Mb2sModPitchPage, mb2s_mod_pitch_page, SC_TYPE_NAVIGATION_PAGE)

static void
mb2s_mod_pitch_page_class_init (Mb2sModPitchPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minibrute2s/mb2s-mod-pitch-page.ui");
}

static void
mb2s_mod_pitch_page_init (Mb2sModPitchPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
