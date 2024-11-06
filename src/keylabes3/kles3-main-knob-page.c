#include "kles3-main-knob-page.h"

struct _Kles3MainKnobPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kles3MainKnobPage, kles3_main_knob_page, SC_TYPE_NAVIGATION_PAGE)

static void
kles3_main_knob_page_class_init (Kles3MainKnobPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes3/kles3-main-knob-page.ui");
}

static void
kles3_main_knob_page_init (Kles3MainKnobPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
