#include "nkls-knob-page.h"

struct _NklsKnobPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (NklsKnobPage, nkls_knob_page, SC_TYPE_NAVIGATION_PAGE)

static void
nkls_knob_page_class_init (NklsKnobPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokontrolstudio/nkls-knob-page.ui");
}

static void
nkls_knob_page_init (NklsKnobPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
