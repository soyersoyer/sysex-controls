#include "nk1-book.h"

#include "nk1-button-page.h"
#include "nk1-cc-mode-page.h"
#include "nk1-keyboard-page.h"
#include "nk1-pitch-bend-page.h"
#include "nk1-scene-page.h"

struct _Nk1Book
{
  KorgBook parent_instance;
};

G_DEFINE_FINAL_TYPE (Nk1Book, nk1_book, KORG_TYPE_BOOK)

static void
nk1_book_class_init (Nk1BookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokey1/nk1-book.ui");
}

static void
nk1_book_init (Nk1Book *self)
{
  const uint8_t nk1_dev_id[4] ={0x00, 0x01, 0x02, 0x00};
  korg_book_set_dev_id (KORG_BOOK (self), nk1_dev_id);

  g_type_ensure (NK1_TYPE_BUTTON_PAGE);
  g_type_ensure (NK1_TYPE_CC_MODE_PAGE);
  g_type_ensure (NK1_TYPE_KEYBOARD_PAGE);
  g_type_ensure (NK1_TYPE_PITCH_BEND_PAGE);
  g_type_ensure (NK1_TYPE_SCENE_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}
