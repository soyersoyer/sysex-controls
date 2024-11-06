#include "kl3-presets-page.h"

struct _Kl3PresetsPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl3PresetsPage, kl3_presets_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl3_presets_page_class_init (Kl3PresetsPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab3/kl3-presets-page.ui");
}

static void
kl3_presets_page_init (Kl3PresetsPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
