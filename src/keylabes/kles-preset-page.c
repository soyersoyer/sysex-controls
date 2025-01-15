#include "kles-preset-page.h"

struct _KlesPresetPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (KlesPresetPage, kles_preset_page, SC_TYPE_NAVIGATION_PAGE)

static void
kles_preset_page_class_init (KlesPresetPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes/kles-preset-page.ui");
}

static void
kles_preset_page_init (KlesPresetPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
