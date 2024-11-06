#include "kles3-presets-page.h"

struct _Kles3PresetsPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kles3PresetsPage, kles3_presets_page, SC_TYPE_NAVIGATION_PAGE)

static void
kles3_presets_page_class_init (Kles3PresetsPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes3/kles3-presets-page.ui");
}

static void
kles3_presets_page_init (Kles3PresetsPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
