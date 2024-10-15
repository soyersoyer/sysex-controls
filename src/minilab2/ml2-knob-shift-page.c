#include "ml2-knob-shift-page.h"

struct _Ml2KnobShiftPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml2KnobShiftPage, ml2_knob_shift_page, SC_TYPE_NAVIGATION_PAGE)

static void
ml2_knob_shift_page_class_init (Ml2KnobShiftPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab2/ml2-knob-shift-page.ui");
}

static void
ml2_knob_shift_page_init (Ml2KnobShiftPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
