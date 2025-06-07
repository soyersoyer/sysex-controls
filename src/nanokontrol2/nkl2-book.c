#include "nkl2-book.h"

#include "nkl2-button-page.h"
#include "nkl2-controller-group-page.h"
#include "nkl2-controller-groups-page.h"
#include "nkl2-function-button-page.h"
#include "nkl2-knob-page.h"
#include "nkl2-scene-page.h"
#include "nkl2-slider-page.h"
#include "nkl2-transport-buttons-page.h"

struct _Nkl2Book
{
  KorgBook parent_instance;
};

G_DEFINE_FINAL_TYPE (Nkl2Book, nkl2_book, KORG_TYPE_BOOK)

static void
nkl2_book_class_init (Nkl2BookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokontrol2/nkl2-book.ui");
}

static void
nkl2_book_init (Nkl2Book *self)
{
  const uint8_t nkl2_dev_id[4] ={0x00, 0x01, 0x13, 0x00};
  korg_book_set_dev_id (KORG_BOOK (self), nkl2_dev_id);

  g_type_ensure (NKL2_TYPE_BUTTON_PAGE);
  g_type_ensure (NKL2_TYPE_CONTROLLER_GROUP_PAGE);
  g_type_ensure (NKL2_TYPE_CONTROLLER_GROUPS_PAGE);
  g_type_ensure (NKL2_TYPE_FUNCTION_BUTTON_PAGE);
  g_type_ensure (NKL2_TYPE_KNOB_PAGE);
  g_type_ensure (NKL2_TYPE_SCENE_PAGE);
  g_type_ensure (NKL2_TYPE_SLIDER_PAGE);
  g_type_ensure (NKL2_TYPE_TRANSPORT_BUTTONS_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}
