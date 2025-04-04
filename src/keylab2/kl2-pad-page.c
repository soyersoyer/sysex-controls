#include "kl2-pad-page.h"

struct _Kl2PadPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl2PadPage, kl2_pad_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl2_pad_page_class_init (Kl2PadPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab2/kl2-pad-page.ui");
}

static void
kl2_pad_page_init (Kl2PadPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
