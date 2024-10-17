#include "ks32-mod-pitch-page.h"

struct _Ks32ModPitchPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ks32ModPitchPage, ks32_mod_pitch_page, SC_TYPE_NAVIGATION_PAGE)

static void
ks32_mod_pitch_page_class_init (Ks32ModPitchPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keystep32/ks32-mod-pitch-page.ui");
}

static void
ks32_mod_pitch_page_init (Ks32ModPitchPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
