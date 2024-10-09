#include "sc-arturia-book.h"

#include "sc-arturia-control.h"
#include "sc-cc-row.h"
#include "sc-combo-row.h"
#include "sc-control-value.h"
#include "sc-note-row.h"
#include "sc-pc-row.h"
#include "sc-preferences-group.h"
#include "sc-preferences-page.h"
#include "sc-midi.h"
#include "sc-window.h"

#define CONTROLS_MAX_N 400

typedef struct
{
  snd_seq_t *seq;
  snd_seq_addr_t seq_addr;
  ScArturiaControl * controls[CONTROLS_MAX_N];
  int controls_n;
} ScArturiaBookPrivate;


G_DEFINE_TYPE_WITH_PRIVATE (ScArturiaBook, sc_arturia_book, ADW_TYPE_BIN)

void
sc_arturia_book_register_control (ScArturiaBook *self, uint32_t control_id, uint32_t real_id, ScArturiaControl *control)
{
  ScArturiaBookPrivate *priv = sc_arturia_book_get_instance_private (self);

  if (priv->controls_n == CONTROLS_MAX_N)
  {
    g_error ("Control space exhausted");
    return;
  }

  priv->controls[priv->controls_n] = control;
  priv->controls_n++;

  g_debug ("sc_arturia_book_register_control 0x%08x as 0x%08x", control_id, real_id);
}

void
sc_arturia_book_load_task (GTask *task, gpointer source_obj, gpointer task_data, GCancellable *cancellable)
{
  ScArturiaBook *self = SC_ARTURIA_BOOK (source_obj);
  ScArturiaBookPrivate *priv = sc_arturia_book_get_instance_private (self);

  g_debug ("sc_arturia_book_load_task start");
  for(int i = 0; i < priv->controls_n; ++i)
  {
    int err = sc_arturia_control_read_value (priv->controls[i]);
    if (err < 0)
    {
      g_task_return_new_error_literal (task, G_IO_ERROR, G_IO_ERROR_FAILED, "control value read failed");
      return;
    }
  }

  g_task_return_boolean (task, true);
  g_debug ("sc_arturia_book_load_task end");
}

void
sc_arturia_book_load_task_finish (GObject* source_object, GAsyncResult* res, gpointer data)
{
  ScArturiaBook *self = SC_ARTURIA_BOOK (source_object);
  ScArturiaBookPrivate *priv = sc_arturia_book_get_instance_private (self);
  ScWindow *window = SC_WINDOW (gtk_widget_get_root (GTK_WIDGET (source_object)));
  GError *error = NULL;
  g_task_propagate_boolean (G_TASK (res), &error);

  if (error)
  {
    sc_io_problem (window, "%s", error->message);
    return;
  }
  for(int i = 0; i < priv->controls_n; ++i)
    sc_arturia_control_update_gui (priv->controls[i]);

  /* TODO: use signals or something better for this */
  sc_window_load_page (window, "setting");
}

void
sc_arturia_book_set_seq (ScArturiaBook *self, snd_seq_t *seq, snd_seq_addr_t addr)
{
  ScArturiaBookPrivate *priv = sc_arturia_book_get_instance_private (self);
  priv->seq = seq;
  priv->seq_addr = addr;
}

snd_seq_t *
sc_arturia_book_get_seq (ScArturiaBook *self)
{
  ScArturiaBookPrivate *priv = sc_arturia_book_get_instance_private (self);
  return priv->seq;
}

snd_seq_addr_t
sc_arturia_book_get_addr (ScArturiaBook *self)
{
  ScArturiaBookPrivate *priv = sc_arturia_book_get_instance_private (self);
  return priv->seq_addr;
}

bool
sc_arturia_book_use_v3 (ScArturiaBook *self)
{
  ScArturiaBookClass *scklass = SC_ARTURIA_BOOK_GET_CLASS (self);
  return scklass->write_control == sc_midi_arturia_v3_write_control;
}

static void
sc_arturia_book_class_init (ScArturiaBookClass *klass)
{
  klass->read_control = sc_midi_arturia_read_control;
  klass->write_control = sc_midi_arturia_write_control;
}

int
sc_arturia_book_read_control (ScArturiaBook *self, uint32_t control_id, uint8_t *val)
{
  ScArturiaBookClass *klass;
  ScArturiaBookPrivate *priv;

  g_return_val_if_fail (SC_IS_ARTURIA_BOOK (self), -EINVAL);

  klass = SC_ARTURIA_BOOK_GET_CLASS (self);
  priv = sc_arturia_book_get_instance_private (self);

  return klass->read_control (priv->seq, priv->seq_addr, control_id, val);
}

int
sc_arturia_book_write_control (ScArturiaBook *self, uint32_t control_id, uint8_t val)
{
  ScArturiaBookClass *klass;
  ScArturiaBookPrivate *priv;

  g_return_val_if_fail (SC_IS_ARTURIA_BOOK (self), -EINVAL);

  klass = SC_ARTURIA_BOOK_GET_CLASS (self);
  priv = sc_arturia_book_get_instance_private (self);

  return klass->write_control (priv->seq, priv->seq_addr, control_id, val);
}

static void
sc_arturia_book_init (ScArturiaBook *self)
{
  g_type_ensure (SC_TYPE_ARTURIA_CONTROL);
  g_type_ensure (SC_TYPE_CC_ROW);
  g_type_ensure (SC_TYPE_COMBO_ROW);
  g_type_ensure (SC_TYPE_CONTROL_VALUE);
  g_type_ensure (SC_TYPE_CONTROL_VALUE_LIST);
  g_type_ensure (SC_TYPE_NOTE_ROW);
  g_type_ensure (SC_TYPE_PC_ROW);
  g_type_ensure (SC_TYPE_PREFERENCES_GROUP);
  g_type_ensure (SC_TYPE_PREFERENCES_PAGE);
}
