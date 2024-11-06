#include "kl3-pad-page.h"

struct _Kl3PadPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl3PadPage, kl3_pad_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl3_pad_page_class_init (Kl3PadPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab3/kl3-pad-page.ui");
}

static void
kl3_pad_page_init (Kl3PadPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
