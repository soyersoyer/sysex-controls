#include "kl3-fader-page.h"

struct _Kl3FaderPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl3FaderPage, kl3_fader_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl3_fader_page_class_init (Kl3FaderPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab3/preset/kl3-fader-page.ui");
}

static void
kl3_fader_page_init (Kl3FaderPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
