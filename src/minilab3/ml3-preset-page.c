#include "ml3-preset-page.h"

struct _Ml3PresetPage
{
  ScPreferencesPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml3PresetPage, ml3_preset_page, SC_TYPE_PREFERENCES_PAGE)

static void
ml3_preset_page_class_init (Ml3PresetPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab3/ml3-preset-page.ui");
}

static void
ml3_preset_page_init (Ml3PresetPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
