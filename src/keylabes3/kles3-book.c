#include "kles3-book.h"

#include "kles3-button.h"
#include "kles3-button-page.h"
#include "kles3-controller-page.h"
#include "kles3-daw-button.h"
#include "kles3-daw-control-row.h"
#include "kles3-fader.h"
#include "kles3-fader-page.h"
#include "kles3-knob.h"
#include "kles3-knob-page.h"
#include "kles3-led-color.h"
#include "kles3-main-knob-page.h"
#include "kles3-pad.h"
#include "kles3-pad-page.h"
#include "kles3-pedal-page.h"
#include "kles3-pitch-mod-page.h"
#include "kles3-preset-page.h"
#include "kles3-presets-page.h"
#include "kles3-velocity-page.h"

struct _Kles3Book
{
  ArBook parent_instance;
};

G_DEFINE_FINAL_TYPE (Kles3Book, kles3_book, AR_TYPE_BOOK)

static void
kles3_book_class_init (Kles3BookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes3/kles3-book.ui");
}

// map 'show preset' into the preset space, for easy display on the preset page 
const remap_t kles3_remap[] = {
  {0x03407f7f, 0x09401300},
  {0x04407f7f, 0x09401400},
  {0x05407f7f, 0x09401500},
  {0x06407f7f, 0x09401600},
  {0x07407f7f, 0x09401700},
  {0x08407f7f, 0x09401800},
  {0x0, 0x0}, // sentinel
};

static void
kles3_book_init (Kles3Book *self)
{
  ArBookClass *scklass = AR_BOOK_GET_CLASS (self);
  scklass->read_control = sc_midi_arturia_v3_read_control;
  scklass->write_control = sc_midi_arturia_v3_write_control;

  ar_book_set_remap (AR_BOOK (self), kles3_remap);

  g_type_ensure (KLES3_TYPE_BUTTON);
  g_type_ensure (KLES3_TYPE_BUTTON_PAGE);
  g_type_ensure (KLES3_TYPE_CONTROLLER_PAGE);
  g_type_ensure (KLES3_TYPE_DAW_BUTTON);
  g_type_ensure (KLES3_TYPE_DAW_CONTROL_ROW);
  g_type_ensure (KLES3_TYPE_FADER);
  g_type_ensure (KLES3_TYPE_FADER_PAGE);
  g_type_ensure (KLES3_TYPE_KNOB);
  g_type_ensure (KLES3_TYPE_KNOB_PAGE);
  g_type_ensure (KLES3_TYPE_LED_COLOR);
  g_type_ensure (KLES3_TYPE_MAIN_KNOB_PAGE);
  g_type_ensure (KLES3_TYPE_PAD);
  g_type_ensure (KLES3_TYPE_PAD_PAGE);
  g_type_ensure (KLES3_TYPE_PEDAL_PAGE);
  g_type_ensure (KLES3_TYPE_PITCH_MOD_PAGE);
  g_type_ensure (KLES3_TYPE_PRESET_PAGE);
  g_type_ensure (KLES3_TYPE_PRESETS_PAGE);
  g_type_ensure (KLES3_TYPE_VELOCITY_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}
