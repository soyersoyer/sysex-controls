#include "kles-knob-page.h"

struct _KlesKnobPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (KlesKnobPage, kles_knob_page, SC_TYPE_NAVIGATION_PAGE)

static void
kles_knob_page_class_init (KlesKnobPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes/kles-knob-page.ui");
}

static void
kles_knob_page_init (KlesKnobPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
