#include "kles-fader-page.h"

struct _KlesFaderPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (KlesFaderPage, kles_fader_page, SC_TYPE_NAVIGATION_PAGE)

static void
kles_fader_page_class_init (KlesFaderPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes/kles-fader-page.ui");
}

static void
kles_fader_page_init (KlesFaderPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
