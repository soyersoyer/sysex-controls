#include "ml-preset-page.h"

struct _MlPresetPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (MlPresetPage, ml_preset_page, SC_TYPE_NAVIGATION_PAGE)

static void
ml_preset_page_class_init (MlPresetPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab/ml-preset-page.ui");
}

static void
ml_preset_page_init (MlPresetPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
