#include "np2-pad-page.h"

struct _Np2PadPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Np2PadPage, np2_pad_page, SC_TYPE_NAVIGATION_PAGE)

static void
np2_pad_page_class_init (Np2PadPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanopad2/np2-pad-page.ui");
}

static void
np2_pad_page_init (Np2PadPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
