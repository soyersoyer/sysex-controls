#include "ml3-presets-page.h"

struct _Ml3PresetsPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml3PresetsPage, ml3_presets_page, SC_TYPE_NAVIGATION_PAGE)

static void
ml3_presets_page_class_init (Ml3PresetsPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab3/ml3-presets-page.ui");
}

static void
ml3_presets_page_init (Ml3PresetsPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
