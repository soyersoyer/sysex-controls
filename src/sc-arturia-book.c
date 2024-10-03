#include "sc-arturia-book.h"

#include "sc-control-value.h"
#include "sc-midi.h"
#include "sc-window.h"

#define CONTROLS_MAX_N 100

typedef struct {
  uint16_t id;
  uint8_t val;
  GtkWidget *widget;
} control_t;

typedef struct
{
  snd_seq_t *seq;
  snd_seq_addr_t seq_addr;
  control_t controls[CONTROLS_MAX_N];
  int controls_n;
} ScArturiaBookPrivate;


G_DEFINE_TYPE_WITH_PRIVATE (ScArturiaBook, sc_arturia_book, ADW_TYPE_BIN)


static control_t *
get_control_by_id (ScArturiaBook *self, uint16_t control_id)
{
  ScArturiaBookPrivate *priv = sc_arturia_book_get_instance_private (self);

  for(int i = 0; i < priv->controls_n; ++i)
    if (priv->controls[i].id == control_id)
      return &priv->controls[i];

  return NULL;
}

static void
combo_row_change_cb (GObject * widget, GParamSpec *pspec, control_t *control)
{
  ScWindow *window = SC_WINDOW (gtk_widget_get_root (GTK_WIDGET (control->widget)));
  ScArturiaBook *book = SC_ARTURIA_BOOK (gtk_widget_get_ancestor (GTK_WIDGET (control->widget), SC_TYPE_ARTURIA_BOOK));
  ScArturiaBookPrivate *priv = sc_arturia_book_get_instance_private (book);
  ScControlValue *item = SC_CONTROL_VALUE (adw_combo_row_get_selected_item (ADW_COMBO_ROW (widget)));
  uint8_t val = sc_control_value_get_value (item);

  if (control->val == val)
    return;

  g_debug ("combo control change %02x: %02x -> %02x %s", control->id, control->val, val, sc_control_value_get_name (item));
  if (sc_midi_write_control (priv->seq, priv->seq_addr, control->id, val) < 0)
  {
    sc_io_problem (window, "Control change failed");
    return;
  }

  control->val = val;
}

static void
switch_row_change_cb (GObject * widget, GParamSpec *pspec, control_t *control)
{
  ScWindow *window = SC_WINDOW (gtk_widget_get_root (GTK_WIDGET (control->widget)));
  ScArturiaBook *book = SC_ARTURIA_BOOK (gtk_widget_get_ancestor (GTK_WIDGET (control->widget), SC_TYPE_ARTURIA_BOOK));
  ScArturiaBookPrivate *priv = sc_arturia_book_get_instance_private (book);
  AdwSwitchRow *w = ADW_SWITCH_ROW (widget);
  uint8_t val = adw_switch_row_get_active (w);

  if (control->val == val)
    return;

  g_debug ("switch control change %02x: %02x -> %02x\n", control->id, control->val, val);
  if (sc_midi_write_control (priv->seq, priv->seq_addr, control->id, val) < 0)
  {
    sc_io_problem (window, "Control change failed");
    return;
  }

  control->val = val;
}

static void
spin_row_change_cb (GObject * widget, GParamSpec *pspec, control_t *control)
{
  ScWindow *window = SC_WINDOW (gtk_widget_get_root (GTK_WIDGET (control->widget)));
  ScArturiaBook *book = SC_ARTURIA_BOOK (gtk_widget_get_ancestor (GTK_WIDGET (control->widget), SC_TYPE_ARTURIA_BOOK));
  ScArturiaBookPrivate *priv = sc_arturia_book_get_instance_private (book);
  AdwSpinRow *w = ADW_SPIN_ROW (control->widget);
  uint8_t val = (uint8_t)adw_spin_row_get_value (w);

  if (control->val == val)
    return;

  g_debug("spin control change %02x: %02x -> %02x", control->id, control->val, val);

  if (sc_midi_write_control (priv->seq, priv->seq_addr, control->id, val) < 0)
  {
    sc_io_problem (window, "Control change failed");

    /*
     * When setting page replaced by search page this spins forever
     * toggle sensitivity to stop, possibly a GTK bug?
     *
     * Now it emit this warning:
     * GtkText - did not receive a focus-out event.
     * If you handle this event, you must return
     * GDK_EVENT_PROPAGATE so the default handler gets the event as well
     */
    gtk_widget_set_sensitive (GTK_WIDGET (w), false);
    gtk_widget_set_sensitive (GTK_WIDGET (w), true);

    return;
  }

  control->val = val;
}

void
sc_arturia_book_register_control (ScArturiaBook *self, uint16_t control_id, GtkWidget *widget)
{
  ScArturiaBookPrivate *priv = sc_arturia_book_get_instance_private (self);
  control_t *control = get_control_by_id (self, control_id);

  if (control)
  {
    g_error ("Control already added: 0x%02x", control_id);
    return;
  }

  if (priv->controls_n == CONTROLS_MAX_N)
  {
    g_error ("Control space exhausted");
    return;
  }

  control = &priv->controls[priv->controls_n];
  priv->controls_n++;

  control->id = control_id;
  control->widget = widget;

  if (ADW_IS_COMBO_ROW (widget))
    g_signal_connect (G_OBJECT (widget), "notify::selected-item", G_CALLBACK (combo_row_change_cb), control);
  else if (ADW_IS_SWITCH_ROW (widget))
    g_signal_connect (G_OBJECT (widget), "notify::active", G_CALLBACK (switch_row_change_cb), control);
  else if (ADW_IS_SPIN_ROW (widget))
    g_signal_connect (G_OBJECT (widget), "notify::value", G_CALLBACK (spin_row_change_cb), control);
  else
    g_error("Unsupported control type: %s id: 0x%02x",
            gtk_widget_get_name (GTK_WIDGET (widget)),
            control_id);

  g_debug ("sc_window_register_control %02x", control_id);
}

static void
update_gui_control (control_t *c)
{
  if (ADW_IS_COMBO_ROW (c->widget))
  {
    guint pos = GTK_INVALID_LIST_POSITION;
    AdwComboRow* combo_row = ADW_COMBO_ROW (c->widget);
    GListModel* list = adw_combo_row_get_model (combo_row);
    for(int i = 0; i < g_list_model_get_n_items (list); ++i)
    {
      ScControlValue *kv = SC_CONTROL_VALUE (g_list_model_get_item (list, i));
      if (sc_control_value_get_value (kv) == c->val)
      {
        pos = i;
        break;
      }
    }

    if (pos != GTK_INVALID_LIST_POSITION)
      adw_combo_row_set_selected (combo_row, pos);

    g_debug("Set combo row id %02x to pos %02x", c->id, pos);
  }
  else if (ADW_IS_SWITCH_ROW (c->widget))
  {
    AdwSwitchRow *switch_row = ADW_SWITCH_ROW (c->widget);
    adw_switch_row_set_active (switch_row, c->val);
    g_debug ("Set switch row with id %02x to %02x", c->id, c->val);
  }
  else if (ADW_IS_SPIN_ROW (c->widget))
  {
    AdwSpinRow *spin_row = ADW_SPIN_ROW (c->widget);
    adw_spin_row_set_value (spin_row, c->val);
    g_debug ("Set spin row with id %02x to %02x", c->id, c->val);
  } else {
    g_error ("Unsupported control type: %s id: 0x%02x",
              gtk_widget_get_name (GTK_WIDGET (c->widget)),
              c->id);
    }
}

/*static void
sc_window_dump_values(ScWindow *window)
{
  for(int i = 0;i < CONTROLS_N; ++i)
  {
    control_t *c = &window->controls[i];
    if (ADW_IS_COMBO_ROW (c->widget))
    {
      ScControlValue *item = SC_CONTROL_VALUE (adw_combo_row_get_selected_item (ADW_COMBO_ROW (c->widget)));
      printf ("%02x:%02x\n", c->id, sc_control_value_get_value (item));
    }
    else if (ADW_IS_SWITCH_ROW (c->widget))
    {
      printf ("%02x:%02x\n", c->id, adw_switch_row_get_active (ADW_SWITCH_ROW (c->widget)));
    }
    else if (ADW_IS_SPIN_ROW (c->widget))
    {
      printf ("%02x:%02x\n", c->id, (int)adw_spin_row_get_value (ADW_SPIN_ROW (c->widget)));
    }
    else
    {
      fprintf (stderr, "Unsupported control type: %s id: 0x%02x\n",
               gtk_widget_get_name (GTK_WIDGET (c->widget)),
               c->id);
    }
  }
}*/

void
sc_arturia_book_load_task (GTask *task, gpointer source_obj, gpointer task_data, GCancellable *cancellable)
{
  ScArturiaBook *self = SC_ARTURIA_BOOK (source_obj);
  ScArturiaBookPrivate *priv = sc_arturia_book_get_instance_private (self);

  g_debug ("sc_arturia_book_load_task start");
  for(int i = 0; i < priv->controls_n; ++i)
  {
    control_t *c = &priv->controls[i];
    int err = sc_midi_read_control (priv->seq, priv->seq_addr, c->id, &c->val);
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
  {
    control_t *c = &priv->controls[i];
    update_gui_control (c);
  }

  /* TODO: use signals or something better for this */
  sc_window_load_page (window, "setting");
}

void
sc_arturia_book_set_seq (ScArturiaBook *self, snd_seq_t *seq, snd_seq_addr_t *addr)
{
  ScArturiaBookPrivate *priv = sc_arturia_book_get_instance_private (self);
  priv->seq = seq;
  priv->seq_addr = *addr;
}

snd_seq_addr_t *
sc_arturia_book_get_addr (ScArturiaBook *self)
{
  ScArturiaBookPrivate *priv = sc_arturia_book_get_instance_private (self);
  return &priv->seq_addr;
}

static void
sc_arturia_book_class_init (ScArturiaBookClass *klass)
{
}

static void
sc_arturia_book_init (ScArturiaBook *self)
{
}
