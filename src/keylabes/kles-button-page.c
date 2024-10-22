#include "kles-button-page.h"

struct _KlesButtonPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (KlesButtonPage, kles_button_page, SC_TYPE_NAVIGATION_PAGE)

static void
kles_button_page_class_init (KlesButtonPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes/kles-button-page.ui");
}

static void
kles_button_page_init (KlesButtonPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
