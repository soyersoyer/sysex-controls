#include "ak-book.h"

#include "ak-control.h"
#include "ak-program-page.h"

G_DEFINE_TYPE (AkBook, ak_book, SC_TYPE_BOOK)

static void
ak_book_class_init (AkBookClass *klass)
{
  ScBookClass *sc_klass = SC_BOOK_CLASS (klass);
  sc_klass->use_dummy = ak_book_use_dummy;

  klass->read_program = sc_midi_akai_read_program;
  klass->write_program = sc_midi_akai_write_program;
}

int
ak_book_read_program (AkBook *self, uint8_t prog_id, uint8_t *data, uint16_t *size)
{
  AkBookClass *klass;
  ScBook *sc_book;

  g_return_val_if_fail (AK_IS_BOOK (self), -EINVAL);

  klass = AK_BOOK_GET_CLASS (self);
  sc_book = SC_BOOK (self);

  return klass->read_program (sc_book_get_seq (sc_book), sc_book_get_addr (sc_book), prog_id, data, size);
}

int
ak_book_write_program (AkBook *self, uint8_t prog_id, uint8_t *data, uint16_t size)
{
  AkBookClass *klass;
  ScBook *sc_book;

  g_return_val_if_fail (AK_IS_BOOK (self), -EINVAL);

  klass = AK_BOOK_GET_CLASS (self);
  sc_book = SC_BOOK (self);

  return klass->write_program (sc_book_get_seq (sc_book), sc_book_get_addr (sc_book), prog_id, data, size);
}

void ak_book_use_dummy (ScBook *self)
{
  AkBookClass *klass = AK_BOOK_GET_CLASS (self);
  klass->read_program = sc_midi_akai_dummy_read_program;
  klass->write_program = sc_midi_akai_dummy_write_program;
}

static void
ak_book_init (AkBook *self)
{
  g_type_ensure (AK_TYPE_CONTROL);
  g_type_ensure (AK_TYPE_PROGRAM_PAGE);
}
