#include "nk2-book.h"

#include "nk2-button-page.h"
#include "nk2-keyboard-page.h"
#include "nk2-pitch-bend-page.h"
#include "nk2-scene-page.h"

struct _Nk2Book
{
  KorgBook parent_instance;
};

G_DEFINE_FINAL_TYPE (Nk2Book, nk2_book, KORG_TYPE_BOOK)

static void
nk2_book_class_init (Nk2BookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokey2/nk2-book.ui");
}

static void
nk2_book_init (Nk2Book *self)
{
  const uint8_t nk2_dev_id[4] ={0x00, 0x01, 0x11, 0x01};
  korg_book_set_dev_id (KORG_BOOK (self), nk2_dev_id);

  g_type_ensure (NK2_TYPE_BUTTON_PAGE);
  g_type_ensure (NK2_TYPE_KEYBOARD_PAGE);
  g_type_ensure (NK2_TYPE_PITCH_BEND_PAGE);
  g_type_ensure (NK2_TYPE_SCENE_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}
