#include "mb2s-user-scale-page.h"

struct _Mb2sUserScalePage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Mb2sUserScalePage, mb2s_user_scale_page, SC_TYPE_NAVIGATION_PAGE)

static void
mb2s_user_scale_page_class_init (Mb2sUserScalePageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minibrute2s/mb2s-user-scale-page.ui");
}

static void
mb2s_user_scale_page_init (Mb2sUserScalePage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
