#include "kl3-display-button-page.h"

struct _Kl3DisplayButtonPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl3DisplayButtonPage, kl3_display_button_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl3_display_button_page_class_init (Kl3DisplayButtonPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab3/preset/kl3-display-button-page.ui");
}

static void
kl3_display_button_page_init (Kl3DisplayButtonPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
