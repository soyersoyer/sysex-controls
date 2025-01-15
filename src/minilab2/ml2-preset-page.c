#include "ml2-preset-page.h"

struct _Ml2PresetPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml2PresetPage, ml2_preset_page, SC_TYPE_NAVIGATION_PAGE)

static void
ml2_preset_page_class_init (Ml2PresetPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab2/ml2-preset-page.ui");
}

static void
ml2_preset_page_init (Ml2PresetPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
