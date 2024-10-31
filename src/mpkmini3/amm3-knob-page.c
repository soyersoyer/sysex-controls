#include "amm3-knob-page.h"

struct _Amm3KnobPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Amm3KnobPage, amm3_knob_page, SC_TYPE_NAVIGATION_PAGE)

static void
amm3_knob_page_class_init (Amm3KnobPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/mpkmini3/amm3-knob-page.ui");
}

static void
amm3_knob_page_init (Amm3KnobPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
