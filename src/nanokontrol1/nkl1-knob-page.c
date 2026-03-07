#include "nkl1-knob-page.h"

struct _Nkl1KnobPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Nkl1KnobPage, nkl1_knob_page, SC_TYPE_NAVIGATION_PAGE)

static void
nkl1_knob_page_class_init (Nkl1KnobPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokontrol1/nkl1-knob-page.ui");
}

static void
nkl1_knob_page_init (Nkl1KnobPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
