#include "ks32-sustain-pedal-page.h"

struct _Ks32SustainPedalPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ks32SustainPedalPage, ks32_sustain_pedal_page, SC_TYPE_NAVIGATION_PAGE)

static void
ks32_sustain_pedal_page_class_init (Ks32SustainPedalPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keystep32/ks32-sustain-pedal-page.ui");
}

static void
ks32_sustain_pedal_page_init (Ks32SustainPedalPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
