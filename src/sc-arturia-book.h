#pragma once

#include <adwaita.h>
#include "sc-midi.h"

G_BEGIN_DECLS

#define SC_TYPE_ARTURIA_BOOK (sc_arturia_book_get_type ())

G_DECLARE_DERIVABLE_TYPE (ScArturiaBook, sc_arturia_book, SC, ARTURIA_BOOK, AdwBin)

struct _ScArturiaBookClass
{
  AdwBinClass parent_class;
};

void sc_arturia_book_set_seq (ScArturiaBook *self, snd_seq_t *seq, snd_seq_addr_t *addr);
snd_seq_addr_t * sc_arturia_book_get_addr (ScArturiaBook *self);
void sc_arturia_book_register_control (ScArturiaBook *self, uint16_t control_id, GtkWidget *widget);
void sc_arturia_book_load_task (GTask *task, gpointer source_obj, gpointer task_data, GCancellable *cancellable);
void sc_arturia_book_load_task_finish (GObject* source_object, GAsyncResult* res, gpointer data);

G_END_DECLS

