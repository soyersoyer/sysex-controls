#include "np1-pad-page.h"

struct _Np1PadPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Np1PadPage, np1_pad_page, SC_TYPE_NAVIGATION_PAGE)

static void
np1_pad_page_class_init (Np1PadPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanopad1/np1-pad-page.ui");
}

static void
np1_pad_page_init (Np1PadPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
