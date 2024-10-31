#include "amm2-knob-page.h"

struct _Amm2KnobPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Amm2KnobPage, amm2_knob_page, SC_TYPE_NAVIGATION_PAGE)

static void
amm2_knob_page_class_init (Amm2KnobPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/mpkmini2/amm2-knob-page.ui");
}

static void
amm2_knob_page_init (Amm2KnobPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
