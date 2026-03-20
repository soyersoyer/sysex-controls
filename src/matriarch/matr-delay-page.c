#include "matr-delay-page.h"

struct _MatrDelayPage {
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE(MatrDelayPage, matr_delay_page, SC_TYPE_NAVIGATION_PAGE)

static void
matr_delay_page_class_init(MatrDelayPageClass *klass) {
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS(klass);

  gtk_widget_class_set_template_from_resource(widget_class, "/hu/irl/sysex-controls/matriarch/matr-delay-page.ui");
}

static void
matr_delay_page_init(MatrDelayPage *self) {
  gtk_widget_init_template(GTK_WIDGET(self));
}
