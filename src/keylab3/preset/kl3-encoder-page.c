#include "kl3-encoder-page.h"

struct _Kl3EncoderPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl3EncoderPage, kl3_encoder_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl3_encoder_page_class_init (Kl3EncoderPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab3/preset/kl3-encoder-page.ui");
}

static void
kl3_encoder_page_init (Kl3EncoderPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
