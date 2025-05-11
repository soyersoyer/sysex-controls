#include "amm-pad-page.h"

struct _AmmPadPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (AmmPadPage, amm_pad_page, SC_TYPE_NAVIGATION_PAGE)

static void
amm_pad_page_class_init (AmmPadPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/mpkmini/amm-pad-page.ui");
}

static void
amm_pad_page_init (AmmPadPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
