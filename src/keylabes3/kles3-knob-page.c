#include "kles3-knob-page.h"

struct _Kles3KnobPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kles3KnobPage, kles3_knob_page, SC_TYPE_NAVIGATION_PAGE)

static void
kles3_knob_page_class_init (Kles3KnobPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes3/kles3-knob-page.ui");
}

static void
kles3_knob_page_init (Kles3KnobPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
