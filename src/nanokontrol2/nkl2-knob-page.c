#include "nkl2-knob-page.h"

struct _Nkl2KnobPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Nkl2KnobPage, nkl2_knob_page, SC_TYPE_NAVIGATION_PAGE)

static void
nkl2_knob_page_class_init (Nkl2KnobPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokontrol2/nkl2-knob-page.ui");
}

static void
nkl2_knob_page_init (Nkl2KnobPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
