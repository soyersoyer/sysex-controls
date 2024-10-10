#include "ml3-knob-page.h"

struct _Ml3KnobPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml3KnobPage, ml3_knob_page, SC_TYPE_NAVIGATION_PAGE)

static void
ml3_knob_page_class_init (Ml3KnobPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab3/ml3-knob-page.ui");
}

static void
ml3_knob_page_init (Ml3KnobPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
