#include "kl3-preset-page.h"

struct _Kl3PresetPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl3PresetPage, kl3_preset_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl3_preset_page_class_init (Kl3PresetPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab3/kl3-preset-page.ui");
}

static void
kl3_preset_page_init (Kl3PresetPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}

