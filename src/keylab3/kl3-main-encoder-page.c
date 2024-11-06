#include "kl3-main-encoder-page.h"

struct _Kl3MainEncoderPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl3MainEncoderPage, kl3_main_encoder_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl3_main_encoder_page_class_init (Kl3MainEncoderPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab3/kl3-main-encoder-page.ui");
}

static void
kl3_main_encoder_page_init (Kl3MainEncoderPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
