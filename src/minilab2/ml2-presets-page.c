#include "ml2-presets-page.h"

struct _Ml2PresetsPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml2PresetsPage, ml2_presets_page, SC_TYPE_NAVIGATION_PAGE)

static void
ml2_presets_page_class_init (Ml2PresetsPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab2/ml2-presets-page.ui");
}

static void
ml2_presets_page_init (Ml2PresetsPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
