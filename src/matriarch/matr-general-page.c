#include "matr-general-page.h"

struct _MatrGeneralPage {
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE(MatrGeneralPage, matr_general_page, SC_TYPE_NAVIGATION_PAGE)

static void
matr_general_page_class_init(MatrGeneralPageClass *klass) {
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS(klass);

  gtk_widget_class_set_template_from_resource(widget_class, "/hu/irl/sysex-controls/matriarch/matr-general-page.ui");
}

static void
matr_general_page_init(MatrGeneralPage *self) {
  gtk_widget_init_template(GTK_WIDGET(self));
}
