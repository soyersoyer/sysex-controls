#include "kles3-preset-page.h"

struct _Kles3PresetPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kles3PresetPage, kles3_preset_page, SC_TYPE_NAVIGATION_PAGE)

static void
kles3_preset_page_class_init (Kles3PresetPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes3/kles3-preset-page.ui");
}

static void
kles3_preset_page_init (Kles3PresetPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
