#include "ar-book.h"

#include "ar-control.h"
#include "ar-firmware-info-group.h"
#include "ar-preset-chooser-page.h"
#include "ar-preset-chooser-row.h"
#include "ar-preset-page.h"
#include "ar2-drum-ch-row.h"
#include "ar2-glob-ch-row.h"
#include "ar2-glob2-ch-row.h"
#include "ar2-note-drop-down.h"
#include "ar2-off-ch-row.h"
#include "ar2-key-ch-row.h"
#include "ar2-rgb-color-row.h"
#include "ar2-user-all-ch-row.h"
#include "ar2-user-ch-row.h"
#include "ar2-user-scale.h"
#include "ar3-active-ch-row.h"
#include "ar3-ch-row.h"
#include "ar3-color-row.h"

typedef struct
{
  uint8_t read_ack;
  uint8_t preset_sync;
} ArBookPrivate;

G_DEFINE_TYPE_WITH_PRIVATE (ArBook, ar_book, SC_TYPE_BOOK)

void
ar_book_set_read_ack (ArBook *self, uint8_t read_ack)
{
  ArBookPrivate *priv = ar_book_get_instance_private (self);
  priv->read_ack = read_ack;
}

void
ar_book_set_preset_sync (ArBook *self, uint8_t preset_sync)
{
  ArBookPrivate *priv = ar_book_get_instance_private (self);
  priv->preset_sync = preset_sync;
}


static void
ar_book_class_init (ArBookClass *klass)
{
  ScBookClass *sc_klass = SC_BOOK_CLASS (klass);
  sc_klass->use_dummy = ar_book_use_dummy;

  klass->read_control = sc_midi_arturia_read_control;
  klass->write_control = sc_midi_arturia_write_control;
  klass->read_string = sc_midi_arturia_read_string;
  klass->write_string = sc_midi_arturia_write_string;
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

static int
sync_preset (ArBookClass *klass, ScBook *sc_book, uint32_t control_id)
{
  int preset_id = control_id >> 16 & 0x7F;

  if (!preset_id)
    return 0;

  /* it needs some time */
  usleep (20*1000);
  g_debug ("store preset: %d", preset_id);
  return klass->store_preset (sc_book_get_seq (sc_book), sc_book_get_addr (sc_book), preset_id);
}

int
ar_book_write_control (ArBook *self, uint32_t control_id, uint8_t val)
{
  ArBookClass *klass;
  ScBook *sc_book;
  ArBookPrivate *priv;
  int ret;

  g_return_val_if_fail (AR_IS_BOOK (self), -EINVAL);

  klass = AR_BOOK_GET_CLASS (self);
  priv = ar_book_get_instance_private (self);
  sc_book = SC_BOOK (self);

  ret = klass->write_control (sc_book_get_seq (sc_book), sc_book_get_addr (sc_book), control_id, val);
  if (ret)
    return ret;

  if (!priv->preset_sync)
    return 0;
  
  return sync_preset (klass, sc_book, control_id);
}

int
ar_book_read_string (ArBook *self, uint32_t control_id, char val[17])
{
  ArBookClass *klass;
  ArBookPrivate *priv;
  ScBook *sc_book;

  g_return_val_if_fail (AR_IS_BOOK (self), -EINVAL);

  klass = AR_BOOK_GET_CLASS (self);
  priv = ar_book_get_instance_private (self);
  sc_book = SC_BOOK (self);

  return klass->read_string (sc_book_get_seq (sc_book), sc_book_get_addr (sc_book), priv->read_ack, control_id, val);
}

int
ar_book_write_string (ArBook *self, uint32_t control_id, char val[17])
{
  ArBookClass *klass;
  ScBook *sc_book;
  ArBookPrivate *priv;
  int ret;

  g_return_val_if_fail (AR_IS_BOOK (self), -EINVAL);

  klass = AR_BOOK_GET_CLASS (self);
  priv = ar_book_get_instance_private (self);
  sc_book = SC_BOOK (self);

  ret = klass->write_string (sc_book_get_seq (sc_book), sc_book_get_addr (sc_book), control_id, val);
  if (ret)
    return ret;

  if (!priv->preset_sync)
    return 0;

  return sync_preset (klass, sc_book, control_id);
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
  klass->read_string = sc_midi_arturia_dummy_read_string;
  klass->write_string = sc_midi_arturia_dummy_write_string;
  klass->recall_preset = sc_midi_arturia_dummy_recall_preset;
  klass->store_preset = sc_midi_arturia_dummy_store_preset;
}

static void
ar_book_init (ArBook *self)
{
  g_type_ensure (AR2_TYPE_DRUM_CH_ROW);
  g_type_ensure (AR2_TYPE_GLOB_CH_ROW);
  g_type_ensure (AR2_TYPE_GLOB2_CH_ROW);
  g_type_ensure (AR2_TYPE_KEY_CH_ROW);
  g_type_ensure (AR2_TYPE_NOTE_DROP_DOWN);
  g_type_ensure (AR2_TYPE_OFF_CH_ROW);
  g_type_ensure (AR2_TYPE_RGB_COLOR_ROW);
  g_type_ensure (AR2_TYPE_USER_ALL_CH_ROW);
  g_type_ensure (AR2_TYPE_USER_CH_ROW);
  g_type_ensure (AR2_TYPE_USER_SCALE);
  g_type_ensure (AR3_TYPE_ACTIVE_CH_ROW);
  g_type_ensure (AR3_TYPE_CH_ROW);
  g_type_ensure (AR3_TYPE_COLOR_ROW);
  g_type_ensure (AR_TYPE_CONTROL);
  g_type_ensure (AR_TYPE_FIRMWARE_INFO_GROUP);
  g_type_ensure (AR_TYPE_PRESET_CHOOSER_PAGE);
  g_type_ensure (AR_TYPE_PRESET_CHOOSER_ROW);
  g_type_ensure (AR_TYPE_PRESET_PAGE);
}
