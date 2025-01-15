#include "kl2-preset-page.h"

struct _Kl2PresetPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl2PresetPage, kl2_preset_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl2_preset_page_class_init (Kl2PresetPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab2/kl2-preset-page.ui");
}

static void
kl2_preset_page_init (Kl2PresetPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
