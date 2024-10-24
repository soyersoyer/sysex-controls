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
#include "ar3-ch-row.h"
#include "ar3-color-row.h"
#include "sc-action-row.h"
#include "sc-cc-row.h"
#include "sc-combo-row.h"
#include "sc-control-value.h"
#include "sc-navigation-page.h"
#include "sc-note-row.h"
#include "sc-pc-row.h"
#include "sc-preferences-group.h"
#include "sc-preferences-page.h"
#include "sc-midi.h"
#include "sc-window.h"

typedef struct
{
  snd_seq_t *seq;
  snd_seq_addr_t seq_addr;
  uint8_t read_ack;
} ArBookPrivate;


G_DEFINE_TYPE_WITH_PRIVATE (ArBook, ar_book, ADW_TYPE_NAVIGATION_PAGE)

void
ar_book_load_task (GTask *task, gpointer source_obj, gpointer task_data, GCancellable *cancellable)
{
  AdwNavigationPage *self = ADW_NAVIGATION_PAGE (source_obj);
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (adw_navigation_page_get_child (self));

  g_debug ("ar_book_load_task start");
  for(GtkWidget *page = gtk_widget_get_first_child (GTK_WIDGET (view));
      page; page = gtk_widget_get_next_sibling (page))
  {
    if (!SC_IS_NAVIGATION_PAGE (page))
      continue;

    if (sc_navigation_page_load_controls (SC_NAVIGATION_PAGE (page)) < 0)
    {
      g_task_return_new_error_literal (task, G_IO_ERROR, G_IO_ERROR_FAILED, "control value read failed");
      return;
    }
  }

  g_task_return_boolean (task, true);
  g_debug ("ar_book_load_task end");
}

void
ar_book_load_task_finish (GObject* source_object, GAsyncResult* res, gpointer data)
{
  AdwNavigationPage *self = ADW_NAVIGATION_PAGE (source_object);
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (adw_navigation_page_get_child (self));

  ScWindow *window = SC_WINDOW (gtk_widget_get_root (GTK_WIDGET (source_object)));
  GError *error = NULL;
  g_task_propagate_boolean (G_TASK (res), &error);

  if (error)
  {
    sc_io_problem (window, "%s", error->message);
    return;
  }
  for(GtkWidget *page = gtk_widget_get_first_child (GTK_WIDGET (view));
      page; page = gtk_widget_get_next_sibling (page))
  {
    if (!SC_IS_NAVIGATION_PAGE (page))
      continue;

    sc_navigation_page_update_gui (SC_NAVIGATION_PAGE (page));
  }

  /* TODO: use signals or something better for this */
  sc_window_load_page (window, "setting");
}

void
ar_book_set_seq (ArBook *self, snd_seq_t *seq, snd_seq_addr_t addr)
{
  ArBookPrivate *priv = ar_book_get_instance_private (self);
  priv->seq = seq;
  priv->seq_addr = addr;
}

void
ar_book_set_read_ack (ArBook *self, uint8_t read_ack)
{
  ArBookPrivate *priv = ar_book_get_instance_private (self);
  priv->read_ack = read_ack;
}

snd_seq_t *
ar_book_get_seq (ArBook *self)
{
  ArBookPrivate *priv = ar_book_get_instance_private (self);
  return priv->seq;
}

snd_seq_addr_t
ar_book_get_addr (ArBook *self)
{
  ArBookPrivate *priv = ar_book_get_instance_private (self);
  return priv->seq_addr;
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

  g_return_val_if_fail (AR_IS_BOOK (self), -EINVAL);

  klass = AR_BOOK_GET_CLASS (self);
  priv = ar_book_get_instance_private (self);

  return klass->read_control (priv->seq, priv->seq_addr, priv->read_ack, control_id, val);
}

int
ar_book_write_control (ArBook *self, uint32_t control_id, uint8_t val)
{
  ArBookClass *klass;
  ArBookPrivate *priv;

  g_return_val_if_fail (AR_IS_BOOK (self), -EINVAL);

  klass = AR_BOOK_GET_CLASS (self);
  priv = ar_book_get_instance_private (self);

  return klass->write_control (priv->seq, priv->seq_addr, control_id, val);
}

int
ar_book_recall_preset (ArBook *self, uint8_t preset_id)
{
  ArBookClass *klass;
  ArBookPrivate *priv;

  g_return_val_if_fail (AR_IS_BOOK (self), -EINVAL);

  klass = AR_BOOK_GET_CLASS (self);
  priv = ar_book_get_instance_private (self);

  return klass->recall_preset (priv->seq, priv->seq_addr, preset_id);
}


int
ar_book_store_preset (ArBook *self, uint8_t preset_id)
{
  ArBookClass *klass;
  ArBookPrivate *priv;

  g_return_val_if_fail (AR_IS_BOOK (self), -EINVAL);

  klass = AR_BOOK_GET_CLASS (self);
  priv = ar_book_get_instance_private (self);

  return klass->store_preset (priv->seq, priv->seq_addr, preset_id);
}

int
ar_book_device_inquiry (ArBook *self, uint8_t data[11])
{
  ArBookPrivate *priv;

  g_return_val_if_fail (AR_IS_BOOK (self), -EINVAL);

  priv = ar_book_get_instance_private (self);

  return sc_midi_arturia_device_inquiry (priv->seq, priv->seq_addr, data);
}

static void
ar_book_init (ArBook *self)
{
  g_type_ensure (AR2_TYPE_GLOB_CH_ROW);
  g_type_ensure (AR2_TYPE_KEY_CH_ROW);
  g_type_ensure (AR2_TYPE_RGB_COLOR_ROW);
  g_type_ensure (AR2_TYPE_USER_CH_ROW);
  g_type_ensure (AR3_TYPE_CH_ROW);
  g_type_ensure (AR3_TYPE_COLOR_ROW);
  g_type_ensure (AR_TYPE_CONTROL);
  g_type_ensure (AR_TYPE_FIRMWARE_INFO_GROUP);
  g_type_ensure (AR_TYPE_PRESET_CHOOSER_PAGE);
  g_type_ensure (AR_TYPE_PRESET_CHOOSER_ROW);
  g_type_ensure (AR_TYPE_PRESET_PAGE);
  g_type_ensure (SC_TYPE_ACTION_ROW);
  g_type_ensure (SC_TYPE_CC_ROW);
  g_type_ensure (SC_TYPE_COMBO_ROW);
  g_type_ensure (SC_TYPE_CONTROL_VALUE);
  g_type_ensure (SC_TYPE_CONTROL_VALUE_LIST);
  g_type_ensure (SC_TYPE_NOTE_ROW);
  g_type_ensure (SC_TYPE_PC_ROW);
  g_type_ensure (SC_TYPE_PREFERENCES_GROUP);
  g_type_ensure (SC_TYPE_PREFERENCES_PAGE);
}
