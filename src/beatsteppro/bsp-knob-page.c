#include "bsp-knob-page.h"

struct _BspKnobPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (BspKnobPage, bsp_knob_page, SC_TYPE_NAVIGATION_PAGE)

static void
bsp_knob_page_class_init (BspKnobPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatsteppro/bsp-knob-page.ui");
}

static void
bsp_knob_page_init (BspKnobPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
