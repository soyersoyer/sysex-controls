#pragma once

#include <adwaita.h>

#include "ar-book.h"

G_BEGIN_DECLS

#define MATR_TYPE_BOOK (matr_book_get_type ())

G_DECLARE_FINAL_TYPE (MatrBook, matr_book, MATR, BOOK, ArBook)

struct _MatrBookClass
{
    ScBookClass parent_class;

    int (*read_control) (snd_seq_t *seq, snd_seq_addr_t addr, uint8_t read_ack, uint8_t control_id, uint16_t *val);
};

int matr_book_read_control (MatrBook *self, uint8_t control_id, uint16_t *val);

G_END_DECLS
