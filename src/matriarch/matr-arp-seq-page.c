#include "matr-arp-seq-page.h"

struct _MatrArpSeqPage {
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE(MatrArpSeqPage, matr_arp_seq_page, SC_TYPE_NAVIGATION_PAGE)

static void
matr_arp_seq_page_class_init(MatrArpSeqPageClass *klass) {
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS(klass);

  gtk_widget_class_set_template_from_resource(widget_class, "/hu/irl/sysex-controls/matriarch/matr-arp-seq-page.ui");
}

static void
matr_arp_seq_page_init(MatrArpSeqPage *self) {
  gtk_widget_init_template(GTK_WIDGET(self));
}
