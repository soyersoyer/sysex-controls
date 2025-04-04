#include "kl3-parts-page.h"

struct _Kl3PartsPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl3PartsPage, kl3_parts_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl3_parts_page_class_init (Kl3PartsPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab3/kl3-parts-page.ui");
}

static void
kl3_parts_page_init (Kl3PartsPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
