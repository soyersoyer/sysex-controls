#include "ml3-global-page.h"

struct _Ml3GlobalPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml3GlobalPage, ml3_global_page, SC_TYPE_NAVIGATION_PAGE)

static void
ml3_global_page_class_init (Ml3GlobalPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab3/ml3-global-page.ui");
}

static void
ml3_global_page_init (Ml3GlobalPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
