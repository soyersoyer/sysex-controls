#pragma once

#include <adwaita.h>
#include "sc-book.h"

G_BEGIN_DECLS

#define KORG_TYPE_BOOK (korg_book_get_type ())

G_DECLARE_DERIVABLE_TYPE (KorgBook, korg_book, KORG, BOOK, ScBook)

struct _KorgBookClass
{
  ScBookClass parent_class;

  int (*change_scene) (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id[4], uint8_t scene_id);
  int (*read_scene) (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id[4], uint8_t scene_id, uint8_t data[512], uint16_t *size);
  int (*write_scene) (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id[4], uint8_t scene_id, uint8_t data[512], uint16_t size);
  int (*save_scene) (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id[4], uint8_t scene_id);
};

void korg_book_set_dev_id (KorgBook *self, const uint8_t dev_id[4]);

int korg_book_change_scene (KorgBook *self, uint8_t scene_id);
int korg_book_read_scene (KorgBook *self, uint8_t scene_id, uint8_t data[512], uint16_t *size);
int korg_book_write_scene (KorgBook *self, uint8_t scene_id, uint8_t data[512], uint16_t size);
int korg_book_device_inquiry (KorgBook *self, uint8_t data[9]);

void korg_book_use_dummy (ScBook *self);

G_END_DECLS
