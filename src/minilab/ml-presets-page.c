#include "ml-presets-page.h"

struct _MlPresetsPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (MlPresetsPage, ml_presets_page, SC_TYPE_NAVIGATION_PAGE)

static void
ml_presets_page_class_init (MlPresetsPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab/ml-presets-page.ui");
}

static void
ml_presets_page_init (MlPresetsPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
