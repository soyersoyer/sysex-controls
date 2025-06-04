#pragma once

#include <adwaita.h>
#include "sc-book.h"

G_BEGIN_DECLS

#define KORG_TYPE_BOOK (korg_book_get_type ())

G_DECLARE_DERIVABLE_TYPE (KorgBook, korg_book, KORG, BOOK, ScBook)

struct _KorgBookClass
{
  ScBookClass parent_class;

  int (*read_scene) (snd_seq_t *seq, snd_seq_addr_t addr, uint16_t dev_id, uint8_t scene_id, uint8_t data[256], uint8_t *size);
  int (*write_scene) (snd_seq_t *seq, snd_seq_addr_t addr, uint16_t dev_id, uint8_t scene_id, uint8_t data[256], uint8_t size);
  int (*save_scene) (snd_seq_t *seq, snd_seq_addr_t addr, uint16_t dev_id, uint8_t scene_id);
};

int korg_book_read_scene (KorgBook *self, uint8_t scene_id, uint8_t data[256], uint8_t *size);
int korg_book_write_scene (KorgBook *self, uint8_t scene_id, uint8_t data[256], uint8_t size);
int korg_book_device_inquiry (KorgBook *self, uint8_t data[9]);

void korg_book_use_dummy (ScBook *self);

G_END_DECLS
