#include "bs-knob-page.h"

struct _BsKnobPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (BsKnobPage, bs_knob_page, SC_TYPE_NAVIGATION_PAGE)

static void
bs_knob_page_class_init (BsKnobPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatstep/bs-knob-page.ui");
}

static void
bs_knob_page_init (BsKnobPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
