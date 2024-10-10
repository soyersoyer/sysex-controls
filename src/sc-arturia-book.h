#pragma once

#include <adwaita.h>
#include "sc-arturia-control.h"
#include "sc-midi.h"

G_BEGIN_DECLS

#define SC_TYPE_ARTURIA_BOOK (sc_arturia_book_get_type ())

G_DECLARE_DERIVABLE_TYPE (ScArturiaBook, sc_arturia_book, SC, ARTURIA_BOOK, AdwNavigationPage)

struct _ScArturiaBookClass
{
  AdwNavigationPageClass parent_class;

  int (*read_control) (snd_seq_t *seq, snd_seq_addr_t addr, uint32_t control_id, uint8_t *val);
  int (*write_control) (snd_seq_t *seq, snd_seq_addr_t addr, uint32_t control_id, uint8_t val);
};

void sc_arturia_book_set_seq (ScArturiaBook *self, snd_seq_t *seq, snd_seq_addr_t addr);
snd_seq_t * sc_arturia_book_get_seq (ScArturiaBook *self);
snd_seq_addr_t sc_arturia_book_get_addr (ScArturiaBook *self);
void sc_arturia_book_register_control (ScArturiaBook *self, uint32_t control_id, uint32_t real_id, ScArturiaControl *control);
bool sc_arturia_book_use_v3 (ScArturiaBook *self);
void sc_arturia_book_load_task (GTask *task, gpointer source_obj, gpointer task_data, GCancellable *cancellable);
void sc_arturia_book_load_task_finish (GObject* source_object, GAsyncResult* res, gpointer data);

int sc_arturia_book_read_control (ScArturiaBook *self, uint32_t control_id, uint8_t *val);
int sc_arturia_book_write_control (ScArturiaBook *self, uint32_t control_id, uint8_t val);

G_END_DECLS
