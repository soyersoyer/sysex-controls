#include "kl2-daw-button-page.h"

struct _Kl2DawButtonPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl2DawButtonPage, kl2_daw_button_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl2_daw_button_page_class_init (Kl2DawButtonPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab2/kl2-daw-button-page.ui");
}

static void
kl2_daw_button_page_init (Kl2DawButtonPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
