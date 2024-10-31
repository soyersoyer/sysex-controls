#pragma once

#include <adwaita.h>
#include "sc-book.h"

G_BEGIN_DECLS

#define AK_TYPE_BOOK (ak_book_get_type ())

G_DECLARE_DERIVABLE_TYPE (AkBook, ak_book, AK, BOOK, ScBook)

struct _AkBookClass
{
  ScBookClass parent_class;

  int (*read_program) (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id, uint8_t prog_id, uint8_t *data, uint16_t *size);
  int (*write_program) (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t dev_id, uint8_t prog_id, uint8_t *data, uint16_t size);
};

void ak_book_set_dev_id (AkBook *self, uint8_t dev_id);

int ak_book_read_program (AkBook *self, uint8_t prog_id, uint8_t *dat, uint16_t *size);
int ak_book_write_program (AkBook *self, uint8_t prog_id, uint8_t *data, uint16_t size);

void ak_book_use_dummy (ScBook *self);

G_END_DECLS
