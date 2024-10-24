#include "kl2-kfs-page.h"

struct _Kl2KfsPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl2KfsPage, kl2_kfs_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl2_kfs_page_class_init (Kl2KfsPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab2/kl2-kfs-page.ui");
}

static void
kl2_kfs_page_init (Kl2KfsPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
