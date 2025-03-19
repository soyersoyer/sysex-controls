#include "ml-pad-page.h"

struct _MlPadPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (MlPadPage, ml_pad_page, SC_TYPE_NAVIGATION_PAGE)

static void
ml_pad_page_class_init (MlPadPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab/ml-pad-page.ui");
}

static void
ml_pad_page_init (MlPadPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
