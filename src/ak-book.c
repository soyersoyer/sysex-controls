#include "ak-book.h"

#include "ak-control.h"
#include "ak-program-page.h"
#include "ak-program-select.h"

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
  klass->select_program = sc_midi_akai_select_program;
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

int
ak_book_select_program (AkBook *self, uint8_t prog_id)
{
  AkBookPrivate *priv;
  AkBookClass *klass;
  ScBook *sc_book;

  g_return_val_if_fail (AK_IS_BOOK (self), -EINVAL);

  priv = ak_book_get_instance_private (self);
  klass = AK_BOOK_GET_CLASS (self);
  sc_book = SC_BOOK (self);

  return klass->select_program (sc_book_get_seq (sc_book), sc_book_get_addr (sc_book), priv->dev_id, prog_id);
}

void
ak_book_refresh_page (AkBook *self, uint8_t prog_id)
{
  AdwNavigationPage *nav_page = ADW_NAVIGATION_PAGE (self);
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (adw_navigation_page_get_child (nav_page));

  for(GtkWidget *page = gtk_widget_get_first_child (GTK_WIDGET (view));
      page; page = gtk_widget_get_next_sibling (page))
  {
    if (!AK_IS_PROGRAM_PAGE (page))
      continue;

    if (prog_id != ak_program_page_get_prog_id (AK_PROGRAM_PAGE (page)))
      continue;

    sc_navigation_page_load_controls_and_update_bg (SC_NAVIGATION_PAGE (page));
  }
}


void ak_book_use_dummy (ScBook *self)
{
  AkBookClass *klass = AK_BOOK_GET_CLASS (self);
  klass->read_program = sc_midi_akai_dummy_read_program;
  klass->write_program = sc_midi_akai_dummy_write_program;
  klass->select_program = sc_midi_akai_dummy_select_program;
}

static void
ak_book_init (AkBook *self)
{
  g_type_ensure (AK_TYPE_CONTROL);
  g_type_ensure (AK_TYPE_PROGRAM_PAGE);
  g_type_ensure (AK_TYPE_PROGRAM_SELECT);
}
