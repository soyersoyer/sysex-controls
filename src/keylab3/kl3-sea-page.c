#include "kl3-sea-page.h"

struct _Kl3SeaPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl3SeaPage, kl3_sea_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl3_sea_page_class_init (Kl3SeaPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab3/kl3-sea-page.ui");
}

static void
kl3_sea_page_init (Kl3SeaPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
