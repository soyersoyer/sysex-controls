#include "mb2-mod-pitch-page.h"

struct _Mb2ModPitchPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Mb2ModPitchPage, mb2_mod_pitch_page, SC_TYPE_NAVIGATION_PAGE)

static void
mb2_mod_pitch_page_class_init (Mb2ModPitchPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minibrute2/mb2-mod-pitch-page.ui");
}

static void
mb2_mod_pitch_page_init (Mb2ModPitchPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
