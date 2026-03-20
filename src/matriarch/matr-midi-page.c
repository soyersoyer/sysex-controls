#include "matr-midi-page.h"

struct _MatrMidiPage {
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE(MatrMidiPage, matr_midi_page, SC_TYPE_NAVIGATION_PAGE)

static void
matr_midi_page_class_init(MatrMidiPageClass *klass) {
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS(klass);

  gtk_widget_class_set_template_from_resource(widget_class, "/hu/irl/sysex-controls/matriarch/matr-midi-page.ui");
}

static void
matr_midi_page_init(MatrMidiPage *self) {
  gtk_widget_init_template(GTK_WIDGET(self));
}
