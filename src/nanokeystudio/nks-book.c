#include "nks-book.h"

#include "nks-button-page.h"
#include "nks-global-page.h"
#include "nks-knob-page.h"
#include "nks-knobs-page.h"
#include "nks-power-management-bat-page.h"
#include "nks-power-management-usb-page.h"
#include "nks-scene-chord-pad-page.h"
#include "nks-scene-keyboard-page.h"
#include "nks-scene-page.h"
#include "nks-scenes-page.h"
#include "nks-touch-pitch-mod-page.h"
#include "nks-touch-scale-page.h"
#include "nks-touch-xy-axis.h"
#include "nks-touch-xy-page.h"
#include "nks-trigger-pad-page.h"
#include "nks-trigger-pads-page.h"

struct _NksBook
{
  KorgBook parent_instance;
};

G_DEFINE_FINAL_TYPE (NksBook, nks_book, KORG_TYPE_BOOK)

static void
nks_book_class_init (NksBookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokeystudio/nks-book.ui");
}

static void
nks_book_init (NksBook *self)
{
  const uint8_t nks_dev_id[4] = {0x00, 0x01, 0x36, 0x00};
  korg_book_set_dev_id (KORG_BOOK (self), nks_dev_id);
  korg_book_set_proto (KORG_BOOK (self), KORG_PROTO_NANO_STUDIO);

  g_type_ensure (NKS_TYPE_BUTTON_PAGE);
  g_type_ensure (NKS_TYPE_GLOBAL_PAGE);
  g_type_ensure (NKS_TYPE_KNOB_PAGE);
  g_type_ensure (NKS_TYPE_KNOBS_PAGE);
  g_type_ensure (NKS_TYPE_POWER_MANAGEMENT_BAT_PAGE);
  g_type_ensure (NKS_TYPE_POWER_MANAGEMENT_USB_PAGE);
  g_type_ensure (NKS_TYPE_SCENE_CHORD_PAD_PAGE);
  g_type_ensure (NKS_TYPE_SCENE_KEYBOARD_PAGE);
  g_type_ensure (NKS_TYPE_SCENE_PAGE);
  g_type_ensure (NKS_TYPE_SCENES_PAGE);
  g_type_ensure (NKS_TYPE_TOUCH_PITCH_MOD_PAGE);
  g_type_ensure (NKS_TYPE_TOUCH_SCALE_PAGE);
  g_type_ensure (NKS_TYPE_TOUCH_XY_AXIS);
  g_type_ensure (NKS_TYPE_TOUCH_XY_PAGE);
  g_type_ensure (NKS_TYPE_TRIGGER_PAD_PAGE);
  g_type_ensure (NKS_TYPE_TRIGGER_PADS_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}
