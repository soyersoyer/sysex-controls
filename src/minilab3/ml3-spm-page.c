#include "ml3-spm-page.h"

struct _Ml3SpmPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml3SpmPage, ml3_spm_page, SC_TYPE_NAVIGATION_PAGE)

static void
ml3_spm_page_class_init (Ml3SpmPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab3/ml3-spm-page.ui");
}

static void
ml3_spm_page_init (Ml3SpmPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
