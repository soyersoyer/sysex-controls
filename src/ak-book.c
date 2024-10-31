#include "ak-book.h"

#include "ak-control.h"
#include "ak-program-page.h"

typedef struct
{
  uint8_t dev_id;
} AkBookPrivate;

G_DEFINE_TYPE_WITH_PRIVATE (AkBook, ak_book, SC_TYPE_BOOK)

void
ak_book_set_dev_id (AkBook *self, uint8_t dev_id)
{
  AkBookPrivate *priv = ak_book_get_instance_private (self);
  priv->dev_id = dev_id;
}

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
  AkBookPrivate *priv;
  AkBookClass *klass;
  ScBook *sc_book;

  g_return_val_if_fail (AK_IS_BOOK (self), -EINVAL);

  priv = ak_book_get_instance_private (self);
  klass = AK_BOOK_GET_CLASS (self);
  sc_book = SC_BOOK (self);


  return klass->read_program (sc_book_get_seq (sc_book), sc_book_get_addr (sc_book), priv->dev_id, prog_id, data, size);
}

int
ak_book_write_program (AkBook *self, uint8_t prog_id, uint8_t *data, uint16_t size)
{
  AkBookPrivate *priv;
  AkBookClass *klass;
  ScBook *sc_book;

  g_return_val_if_fail (AK_IS_BOOK (self), -EINVAL);

  priv = ak_book_get_instance_private (self);
  klass = AK_BOOK_GET_CLASS (self);
  sc_book = SC_BOOK (self);

  return klass->write_program (sc_book_get_seq (sc_book), sc_book_get_addr (sc_book), priv->dev_id, prog_id, data, size);
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
