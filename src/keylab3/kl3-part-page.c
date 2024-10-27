#include "kl3-part-page.h"

struct _Kl3PartPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl3PartPage, kl3_part_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl3_part_page_class_init (Kl3PartPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab3/kl3-part-page.ui");
}

static void
kl3_part_page_init (Kl3PartPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
