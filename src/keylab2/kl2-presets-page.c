#include "kl2-presets-page.h"

struct _Kl2PresetsPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl2PresetsPage, kl2_presets_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl2_presets_page_class_init (Kl2PresetsPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab2/kl2-presets-page.ui");
}

static void
kl2_presets_page_init (Kl2PresetsPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
