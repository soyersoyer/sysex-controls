#include "nkls-book.h"

#include "nkls-button-page.h"
#include "nkls-controller-group-page.h"
#include "nkls-controller-groups-page.h"
#include "nkls-global-page.h"
#include "nkls-jog-wheel-page.h"
#include "nkls-knob-page.h"
#include "nkls-power-management-bat-page.h"
#include "nkls-power-management-usb-page.h"
#include "nkls-scene-page.h"
#include "nkls-scenes-page.h"
#include "nkls-slider-page.h"
#include "nkls-transport-buttons-page.h"

struct _NklsBook
{
  KorgBook parent_instance;
};

G_DEFINE_FINAL_TYPE (NklsBook, nkls_book, KORG_TYPE_BOOK)

static void
nkls_book_class_init (NklsBookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokontrolstudio/nkls-book.ui");
}

static void
nkls_book_init (NklsBook *self)
{
  const uint8_t nkls_dev_id[4] = {0x00, 0x01, 0x37, 0x00};
  korg_book_set_dev_id (KORG_BOOK (self), nkls_dev_id);
  korg_book_set_proto (KORG_BOOK (self), KORG_PROTO_NANO_STUDIO);

  g_type_ensure (NKLS_TYPE_BUTTON_PAGE);
  g_type_ensure (NKLS_TYPE_CONTROLLER_GROUP_PAGE);
  g_type_ensure (NKLS_TYPE_CONTROLLER_GROUPS_PAGE);
  g_type_ensure (NKLS_TYPE_GLOBAL_PAGE);
  g_type_ensure (NKLS_TYPE_JOG_WHEEL_PAGE);
  g_type_ensure (NKLS_TYPE_KNOB_PAGE);
  g_type_ensure (NKLS_TYPE_POWER_MANAGEMENT_BAT_PAGE);
  g_type_ensure (NKLS_TYPE_POWER_MANAGEMENT_USB_PAGE);
  g_type_ensure (NKLS_TYPE_SCENE_PAGE);
  g_type_ensure (NKLS_TYPE_SCENES_PAGE);
  g_type_ensure (NKLS_TYPE_SLIDER_PAGE);
  g_type_ensure (NKLS_TYPE_TRANSPORT_BUTTONS_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}

