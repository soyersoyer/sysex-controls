#include "ml-knob-page.h"

struct _MlKnobPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (MlKnobPage, ml_knob_page, SC_TYPE_NAVIGATION_PAGE)

static void
ml_knob_page_class_init (MlKnobPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab/ml-knob-page.ui");
}

static void
ml_knob_page_init (MlKnobPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
