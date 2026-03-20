#include "matr-cv-page.h"

struct _MatrCvPage {
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE(MatrCvPage, matr_cv_page, SC_TYPE_NAVIGATION_PAGE)

static void
matr_cv_page_class_init(MatrCvPageClass *klass) {
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS(klass);

  gtk_widget_class_set_template_from_resource(widget_class, "/hu/irl/sysex-controls/matriarch/matr-cv-page.ui");
}

static void
matr_cv_page_init(MatrCvPage *self) {
  gtk_widget_init_template(GTK_WIDGET(self));
}
