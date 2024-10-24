#include "kl2-cv-page.h"

struct _Kl2CvPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl2CvPage, kl2_cv_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl2_cv_page_class_init (Kl2CvPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab2/kl2-cv-page.ui");
}

static void
kl2_cv_page_init (Kl2CvPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
