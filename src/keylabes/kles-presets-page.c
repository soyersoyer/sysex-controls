#include "kles-presets-page.h"

struct _KlesPresetsPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (KlesPresetsPage, kles_presets_page, SC_TYPE_NAVIGATION_PAGE)

static void
kles_presets_page_class_init (KlesPresetsPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes/kles-presets-page.ui");
}

static void
kles_presets_page_init (KlesPresetsPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
