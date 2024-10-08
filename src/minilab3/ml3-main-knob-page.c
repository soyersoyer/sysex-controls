#include "ml3-main-knob-page.h"

struct _Ml3MainKnobPage
{
  ScPreferencesPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml3MainKnobPage, ml3_main_knob_page, SC_TYPE_PREFERENCES_PAGE)

static void
ml3_main_knob_page_class_init (Ml3MainKnobPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab3/ml3-main-knob-page.ui");
}

static void
ml3_main_knob_page_init (Ml3MainKnobPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
