#include "np2-xy-pad-ts-page.h"

struct _Np2XyPadTsPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Np2XyPadTsPage, np2_xy_pad_ts_page, SC_TYPE_NAVIGATION_PAGE)

static void
np2_xy_pad_ts_page_class_init (Np2XyPadTsPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanopad2/np2-xy-pad-ts-page.ui");
}

static void
np2_xy_pad_ts_page_init (Np2XyPadTsPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
