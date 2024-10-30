#pragma once

#include <adwaita.h>
#include "sc-midi.h"

G_BEGIN_DECLS

#define SC_TYPE_BOOK (sc_book_get_type ())

G_DECLARE_DERIVABLE_TYPE (ScBook, sc_book, SC, BOOK, AdwNavigationPage)

struct _ScBookClass
{
  AdwNavigationPageClass parent_class;

  void (*use_dummy) (ScBook *self);
};

void sc_book_set_seq (ScBook *self, snd_seq_t *seq, snd_seq_addr_t addr);
snd_seq_t * sc_book_get_seq (ScBook *self);
snd_seq_addr_t sc_book_get_addr (ScBook *self);
int sc_book_load (ScBook *book);
void sc_book_use_dummy (ScBook *self);

G_END_DECLS
