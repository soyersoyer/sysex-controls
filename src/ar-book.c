#include "ar-book.h"

#include "ar-control.h"
#include "ar-firmware-info-group.h"
#include "ar-preset-chooser-page.h"
#include "ar-preset-chooser-row.h"
#include "ar-preset-page.h"
#include "ar2-glob-ch-row.h"
#include "ar2-key-ch-row.h"
#include "ar2-rgb-color-row.h"
#include "ar2-user-ch-row.h"
#include "ar3-active-ch-row.h"
#include "ar3-ch-row.h"
#include "ar3-color-row.h"

typedef struct
{
  uint8_t read_ack;
} ArBookPrivate;

G_DEFINE_TYPE_WITH_PRIVATE (ArBook, ar_book, SC_TYPE_BOOK)

void
ar_book_set_read_ack (ArBook *self, uint8_t read_ack)
{
  ArBookPrivate *priv = ar_book_get_instance_private (self);
  priv->read_ack = read_ack;
}

static void
ar_book_class_init (ArBookClass *klass)
{
  klass->read_control = sc_midi_arturia_read_control;
  klass->write_control = sc_midi_arturia_write_control;
  klass->recall_preset = sc_midi_arturia_recall_preset;
  klass->store_preset = sc_midi_arturia_store_preset;
}

int
ar_book_read_control (ArBook *self, uint32_t control_id, uint8_t *val)
{
  ArBookClass *klass;
  ArBookPrivate *priv;
  ScBook *sc_book;

  g_return_val_if_fail (AR_IS_BOOK (self), -EINVAL);

  klass = AR_BOOK_GET_CLASS (self);
  priv = ar_book_get_instance_private (self);
  sc_book = SC_BOOK (self);

  return klass->read_control (sc_book_get_seq (sc_book), sc_book_get_addr (sc_book), priv->read_ack, control_id, val);
}

int
ar_book_write_control (ArBook *self, uint32_t control_id, uint8_t val)
{
  ArBookClass *klass;
  ScBook *sc_book;

  g_return_val_if_fail (AR_IS_BOOK (self), -EINVAL);

  klass = AR_BOOK_GET_CLASS (self);
  sc_book = SC_BOOK (self);

  return klass->write_control (sc_book_get_seq (sc_book), sc_book_get_addr (sc_book), control_id, val);
}

int
ar_book_recall_preset (ArBook *self, uint8_t preset_id)
{
  ArBookClass *klass;
  ScBook *sc_book;

  g_return_val_if_fail (AR_IS_BOOK (self), -EINVAL);

  klass = AR_BOOK_GET_CLASS (self);
  sc_book = SC_BOOK (self);

  return klass->recall_preset (sc_book_get_seq (sc_book), sc_book_get_addr (sc_book), preset_id);
}


int
ar_book_store_preset (ArBook *self, uint8_t preset_id)
{
  ArBookClass *klass;
  ScBook *sc_book;

  g_return_val_if_fail (AR_IS_BOOK (self), -EINVAL);

  klass = AR_BOOK_GET_CLASS (self);
  sc_book = SC_BOOK (self);

  return klass->store_preset (sc_book_get_seq (sc_book), sc_book_get_addr (sc_book), preset_id);
}

int
ar_book_device_inquiry (ArBook *self, uint8_t data[11])
{
  ScBook *sc_book;

  g_return_val_if_fail (AR_IS_BOOK (self), -EINVAL);

  sc_book = SC_BOOK (self);

  return sc_midi_arturia_device_inquiry (sc_book_get_seq (sc_book), sc_book_get_addr (sc_book), data);
}

void ar_book_use_dummy (ScBook *self)
{
  ArBookClass *klass = AR_BOOK_GET_CLASS (self);
  klass->read_control = sc_midi_arturia_dummy_read_control;
  klass->write_control = sc_midi_arturia_dummy_write_control;
  klass->recall_preset = sc_midi_arturia_dummy_recall_preset;
  klass->store_preset = sc_midi_arturia_dummy_store_preset;
}

static void
ar_book_init (ArBook *self)
{
  ScBookClass *sc_klass = SC_BOOK_GET_CLASS (self);
  sc_klass->use_dummy = ar_book_use_dummy;

  g_type_ensure (AR2_TYPE_GLOB_CH_ROW);
  g_type_ensure (AR2_TYPE_KEY_CH_ROW);
  g_type_ensure (AR2_TYPE_RGB_COLOR_ROW);
  g_type_ensure (AR2_TYPE_USER_CH_ROW);
  g_type_ensure (AR3_TYPE_ACTIVE_CH_ROW);
  g_type_ensure (AR3_TYPE_CH_ROW);
  g_type_ensure (AR3_TYPE_COLOR_ROW);
  g_type_ensure (AR_TYPE_CONTROL);
  g_type_ensure (AR_TYPE_FIRMWARE_INFO_GROUP);
  g_type_ensure (AR_TYPE_PRESET_CHOOSER_PAGE);
  g_type_ensure (AR_TYPE_PRESET_CHOOSER_ROW);
  g_type_ensure (AR_TYPE_PRESET_PAGE);
}
