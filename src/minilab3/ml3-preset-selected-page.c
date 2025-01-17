#include "ml3-preset-selected-page.h"

struct _Ml3PresetSelectedPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml3PresetSelectedPage, ml3_preset_selected_page, SC_TYPE_NAVIGATION_PAGE)

static void
ml3_preset_selected_page_class_init (Ml3PresetSelectedPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab3/ml3-preset-selected-page.ui");
}

static void
ml3_preset_selected_page_init (Ml3PresetSelectedPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
