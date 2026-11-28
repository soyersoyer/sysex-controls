#include "nks-knob-page.h"

struct _NksKnobPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (NksKnobPage, nks_knob_page, SC_TYPE_NAVIGATION_PAGE)

static void
nks_knob_page_class_init (NksKnobPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokeystudio/nks-knob-page.ui");
}

static void
nks_knob_page_init (NksKnobPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
