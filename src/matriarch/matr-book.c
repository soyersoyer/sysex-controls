#include "matr-book.h"

#include "matr-arp-seq-page.h"
#include "matr-cv-page.h"
#include "matr-delay-page.h"
#include "matr-general-page.h"
#include "matr-midi-page.h"

struct _MatrBook {
  ScBookClass parent_instance;

  int (*read_control)(snd_seq_t *seq, snd_seq_addr_t addr, uint32_t control_id, uint16_t *val);

  int (*write_control)(snd_seq_t *seq, snd_seq_addr_t addr, uint32_t control_id, uint16_t val);
};

G_DEFINE_FINAL_TYPE(MatrBook, matr_book, SC_TYPE_BOOK)

static void
matr_book_class_init(MatrBookClass *klass) {
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS(klass);

  gtk_widget_class_set_template_from_resource(widget_class, "/hu/irl/sysex-controls/matriarch/matr-book.ui");
}

static void
matr_book_init(MatrBook *self) {
  self->read_control = sc_midi_matriarch_read_control;
  self->write_control = sc_midi_matriarch_write_control;

  g_type_ensure(MATR_TYPE_ARP_SEQ_PAGE);
  g_type_ensure(MATR_TYPE_CV_PAGE);
  g_type_ensure(MATR_TYPE_DELAY_PAGE);
  g_type_ensure(MATR_TYPE_GENERAL_PAGE);
  g_type_ensure(MATR_TYPE_MIDI_PAGE);

  gtk_widget_init_template(GTK_WIDGET(self));
}


int
matr_book_read_control(MatrBook *self, uint8_t control_id, uint16_t *val) {
  ScBook *sc_book = SC_BOOK(self);
  return self->read_control(sc_book_get_seq(sc_book), sc_book_get_addr(sc_book), control_id, val);
}


int
matr_book_write_control(MatrBook *self, uint8_t control_id, uint16_t val) {
  ScBook *sc_book = SC_BOOK(self);
  return self->write_control(sc_book_get_seq(sc_book), sc_book_get_addr(sc_book), control_id, val);
}
