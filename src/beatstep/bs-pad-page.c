#include "bs-pad-page.h"

struct _BsPadPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (BsPadPage, bs_pad_page, SC_TYPE_NAVIGATION_PAGE)

static void
bs_pad_page_class_init (BsPadPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatstep/bs-pad-page.ui");
}

static void
bs_pad_page_init (BsPadPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
