#include "korg-book.h"
#include "sc-navigation-page.h"
#include "mm-control.h"
#include "korg-scene-page.h"

#include "korg-firmware-info-group.h"

typedef struct
{
  uint8_t dev_id;
} KorgBookPrivate;

G_DEFINE_TYPE_WITH_PRIVATE (KorgBook, korg_book, SC_TYPE_BOOK)

static void
korg_book_class_init (KorgBookClass *klass)
{
  ScBookClass *sc_klass = SC_BOOK_CLASS (klass);
  sc_klass->use_dummy = korg_book_use_dummy;

  klass->read_scene = sc_midi_korg_read_scene;
  klass->write_scene = sc_midi_korg_write_scene;
  klass->save_scene = sc_midi_korg_save_scene;
}

int
korg_book_read_scene (KorgBook *self, uint8_t scene_id, uint8_t data[256], uint8_t *size)
{
  KorgBookPrivate *priv;
  KorgBookClass *klass;
  ScBook *sc_book;

  g_return_val_if_fail (KORG_IS_BOOK (self), -EINVAL);

  priv = korg_book_get_instance_private (self);
  klass = KORG_BOOK_GET_CLASS (self);
  sc_book = SC_BOOK (self);


  return klass->read_scene (sc_book_get_seq (sc_book), sc_book_get_addr (sc_book), priv->dev_id, scene_id, data, size);
}

int
korg_book_write_scene (KorgBook *self, uint8_t scene_id, uint8_t data[256], uint8_t size)
{
  KorgBookPrivate *priv;
  KorgBookClass *klass;
  ScBook *sc_book;
  int err;

  g_return_val_if_fail (KORG_IS_BOOK (self), -EINVAL);

  priv = korg_book_get_instance_private (self);
  klass = KORG_BOOK_GET_CLASS (self);
  sc_book = SC_BOOK (self);

  err = klass->write_scene (sc_book_get_seq (sc_book), sc_book_get_addr (sc_book), priv->dev_id, scene_id, data, size);
  if (err < 0)
    return err;
  return klass->save_scene (sc_book_get_seq (sc_book), sc_book_get_addr (sc_book), priv->dev_id, scene_id);
}

int
korg_book_device_inquiry (KorgBook *self, uint8_t data[9])
{
  ScBook *sc_book;

  g_return_val_if_fail (KORG_IS_BOOK (self), -EINVAL);

  sc_book = SC_BOOK (self);

  return sc_midi_korg_device_inquiry (sc_book_get_seq (sc_book), sc_book_get_addr (sc_book), data);
}

void korg_book_use_dummy (ScBook *self)
{
  KorgBookClass *klass = KORG_BOOK_GET_CLASS (self);
  klass->read_scene = sc_midi_korg_dummy_read_scene;
  klass->write_scene = sc_midi_korg_dummy_write_scene;
  klass->save_scene = sc_midi_korg_dummy_save_scene;
}

static void
korg_book_init (KorgBook *self)
{
  g_type_ensure (MM_TYPE_CONTROL);
  g_type_ensure (KORG_TYPE_SCENE_PAGE);
  g_type_ensure (KORG_TYPE_FIRMWARE_INFO_GROUP);
}
