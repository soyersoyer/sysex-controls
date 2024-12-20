#include "ksp-metronome-page.h"

struct _KspMetronomePage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (KspMetronomePage, ksp_metronome_page, SC_TYPE_NAVIGATION_PAGE)

static void
ksp_metronome_page_class_init (KspMetronomePageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keysteppro/ksp-metronome-page.ui");
}

static void
ksp_metronome_page_init (KspMetronomePage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
