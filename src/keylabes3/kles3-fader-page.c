#include "kles3-fader-page.h"

struct _Kles3FaderPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kles3FaderPage, kles3_fader_page, SC_TYPE_NAVIGATION_PAGE)

static void
kles3_fader_page_class_init (Kles3FaderPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes3/kles3-fader-page.ui");
}

static void
kles3_fader_page_init (Kles3FaderPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
