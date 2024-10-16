#include "ml2-knob-extra-page.h"

struct _Ml2KnobExtraPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml2KnobExtraPage, ml2_knob_extra_page, SC_TYPE_NAVIGATION_PAGE)

static void
ml2_knob_extra_page_class_init (Ml2KnobExtraPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab2/ml2-knob-extra-page.ui");
}

static void
ml2_knob_extra_page_init (Ml2KnobExtraPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
