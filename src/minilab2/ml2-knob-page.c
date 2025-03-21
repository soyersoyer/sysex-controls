#include "ml2-knob-page.h"

struct _Ml2KnobPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml2KnobPage, ml2_knob_page, SC_TYPE_NAVIGATION_PAGE)

static void
ml2_knob_page_class_init (Ml2KnobPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab2/ml2-knob-page.ui");
}

static void
ml2_knob_page_init (Ml2KnobPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
