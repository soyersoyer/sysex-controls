#include "sc-book.h"

#include "sc-action-row.h"
#include "sc-cc-row.h"
#include "sc-ch-row.h"
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
} ScBookPrivate;


G_DEFINE_TYPE_WITH_PRIVATE (ScBook, sc_book, ADW_TYPE_NAVIGATION_PAGE)

static void
sc_book_load_task (GTask *task, gpointer source_obj, gpointer task_data, GCancellable *cancellable)
{
  AdwNavigationPage *self = ADW_NAVIGATION_PAGE (source_obj);
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (adw_navigation_page_get_child (self));

  g_debug ("%s start", __func__);
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
  g_debug ("%s end", __func__);
}

static void
sc_book_load_task_finish (GObject* source_object, GAsyncResult* res, gpointer data)
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
  sc_window_pop_page (window);
}

int
sc_book_load (ScBook *book)
{
  GTask *task = g_task_new (book, NULL, sc_book_load_task_finish, NULL);
  g_task_run_in_thread (task, sc_book_load_task);
  g_object_unref (task);
  return false;
}

void
sc_book_set_seq (ScBook *self, snd_seq_t *seq, snd_seq_addr_t addr)
{
  ScBookPrivate *priv = sc_book_get_instance_private (self);
  priv->seq = seq;
  priv->seq_addr = addr;
}

snd_seq_t *
sc_book_get_seq (ScBook *self)
{
  ScBookPrivate *priv = sc_book_get_instance_private (self);
  return priv->seq;
}

snd_seq_addr_t
sc_book_get_addr (ScBook *self)
{
  ScBookPrivate *priv = sc_book_get_instance_private (self);
  return priv->seq_addr;
}

void
sc_book_use_dummy (ScBook *self)
{
  ScBookClass *klass;

  g_return_if_fail (SC_IS_BOOK (self));

  klass = SC_BOOK_GET_CLASS (self);

  g_return_if_fail (klass->use_dummy != NULL);

  return klass->use_dummy (self);
}

static void
sc_book_class_init (ScBookClass *klass)
{
}

static void
sc_book_init (ScBook *self)
{
  g_type_ensure (SC_TYPE_ACTION_ROW);
  g_type_ensure (SC_TYPE_CC_ROW);
  g_type_ensure (SC_TYPE_CH_ROW);
  g_type_ensure (SC_TYPE_COMBO_ROW);
  g_type_ensure (SC_TYPE_CONTROL_VALUE);
  g_type_ensure (SC_TYPE_CONTROL_VALUE_LIST);
  g_type_ensure (SC_TYPE_NOTE_ROW);
  g_type_ensure (SC_TYPE_PC_ROW);
  g_type_ensure (SC_TYPE_PREFERENCES_GROUP);
  g_type_ensure (SC_TYPE_PREFERENCES_PAGE);
}
