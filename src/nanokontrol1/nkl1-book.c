#include "nkl1-book.h"

#include "nkl1-button-page.h"
#include "nkl1-controller-group-page.h"
#include "nkl1-controller-groups-page.h"
#include "nkl1-knob-page.h"
#include "nkl1-scene-page.h"
#include "nkl1-scenes-page.h"
#include "nkl1-slider-page.h"
#include "nkl1-transport-button-page.h"
#include "nkl1-transport-buttons-page.h"

struct _Nkl1Book
{
  KorgBook parent_instance;
};

G_DEFINE_FINAL_TYPE (Nkl1Book, nkl1_book, KORG_TYPE_BOOK)

static void
nkl1_book_class_init (Nkl1BookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokontrol1/nkl1-book.ui");
}

static void
nkl1_book_init (Nkl1Book *self)
{
  const uint8_t nkl1_dev_id[4] ={0x00, 0x01, 0x04, 0x00};
  korg_book_set_dev_id (KORG_BOOK (self), nkl1_dev_id);

  g_type_ensure (NKL1_TYPE_BUTTON_PAGE);
  g_type_ensure (NKL1_TYPE_CONTROLLER_GROUP_PAGE);
  g_type_ensure (NKL1_TYPE_CONTROLLER_GROUPS_PAGE);
  g_type_ensure (NKL1_TYPE_KNOB_PAGE);
  g_type_ensure (NKL1_TYPE_SCENE_PAGE);
  g_type_ensure (NKL1_TYPE_SCENES_PAGE);
  g_type_ensure (NKL1_TYPE_SLIDER_PAGE);
  g_type_ensure (NKL1_TYPE_TRANSPORT_BUTTON_PAGE);
  g_type_ensure (NKL1_TYPE_TRANSPORT_BUTTONS_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}
