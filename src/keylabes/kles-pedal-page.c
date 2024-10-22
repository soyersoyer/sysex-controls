#include "kles-pedal-page.h"

struct _KlesPedalPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (KlesPedalPage, kles_pedal_page, SC_TYPE_NAVIGATION_PAGE)

static void
kles_pedal_page_class_init (KlesPedalPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes/kles-pedal-page.ui");
}

static void
kles_pedal_page_init (KlesPedalPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
