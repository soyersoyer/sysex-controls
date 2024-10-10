#include "ml3-mod-page.h"

struct _Ml3ModPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml3ModPage, ml3_mod_page, SC_TYPE_NAVIGATION_PAGE)

static void
ml3_mod_page_class_init (Ml3ModPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab3/ml3-mod-page.ui");
}

static void
ml3_mod_page_init (Ml3ModPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
