#include "ksp-knob-page.h"

struct _KspKnobPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (KspKnobPage, ksp_knob_page, SC_TYPE_NAVIGATION_PAGE)

static void
ksp_knob_page_class_init (KspKnobPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keysteppro/ksp-knob-page.ui");
}

static void
ksp_knob_page_init (KspKnobPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
