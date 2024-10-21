#include "kles3-button-page.h"

struct _Kles3ButtonPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kles3ButtonPage, kles3_button_page, SC_TYPE_NAVIGATION_PAGE)

static void
kles3_button_page_class_init (Kles3ButtonPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes3/preset/kles3-button-page.ui");
}

static void
kles3_button_page_init (Kles3ButtonPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
