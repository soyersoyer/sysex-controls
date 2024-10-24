#pragma once

#include <adwaita.h>
#include "sc-midi.h"

G_BEGIN_DECLS

#define AR_TYPE_BOOK (ar_book_get_type ())

G_DECLARE_DERIVABLE_TYPE (ArBook, ar_book, AR, BOOK, AdwNavigationPage)

struct _ArBookClass
{
  AdwNavigationPageClass parent_class;

  int (*read_control) (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t read_ack, uint32_t control_id, uint8_t *val);
  int (*write_control) (snd_seq_t *seq, snd_seq_addr_t addr, uint32_t control_id, uint8_t val);
  int (*recall_preset) (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t preset_id);
  int (*store_preset) (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t preset_id);
};

void ar_book_set_seq (ArBook *self, snd_seq_t *seq, snd_seq_addr_t addr);
void ar_book_set_read_ack (ArBook *self, uint8_t read_ack);
snd_seq_t * ar_book_get_seq (ArBook *self);
snd_seq_addr_t ar_book_get_addr (ArBook *self);
void ar_book_load_task (GTask *task, gpointer source_obj, gpointer task_data, GCancellable *cancellable);
void ar_book_load_task_finish (GObject* source_object, GAsyncResult* res, gpointer data);

int ar_book_read_control (ArBook *self, uint32_t control_id, uint8_t *val);
int ar_book_write_control (ArBook *self, uint32_t control_id, uint8_t val);
int ar_book_recall_preset (ArBook *self, uint8_t preset_id);
int ar_book_store_preset (ArBook *self, uint8_t preset_id);
int ar_book_device_inquiry (ArBook *self, uint8_t data[11]);

void ar_book_use_dummy (ArBook *self);

G_END_DECLS
