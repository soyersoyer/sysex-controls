#include "np2-xy-pad-cc-page.h"

struct _Np2XyPadCcPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Np2XyPadCcPage, np2_xy_pad_cc_page, SC_TYPE_NAVIGATION_PAGE)

static void
np2_xy_pad_cc_page_class_init (Np2XyPadCcPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanopad2/np2-xy-pad-cc-page.ui");
}

static void
np2_xy_pad_cc_page_init (Np2XyPadCcPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
