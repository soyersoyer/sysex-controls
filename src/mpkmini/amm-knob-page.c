#include "amm-knob-page.h"

struct _AmmKnobPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (AmmKnobPage, amm_knob_page, SC_TYPE_NAVIGATION_PAGE)

static void
amm_knob_page_class_init (AmmKnobPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/mpkmini/amm-knob-page.ui");
}

static void
amm_knob_page_init (AmmKnobPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
