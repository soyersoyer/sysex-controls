#include "ml3-book.h"

#include "ml3-controller-page.h"
#include "ml3-fader.h"
#include "ml3-fader-page.h"
#include "ml3-knob.h"
#include "ml3-knob-page.h"
#include "ml3-main-knob.h"
#include "ml3-main-knob-click.h"
#include "ml3-main-knob-page.h"
#include "ml3-pad.h"
#include "ml3-pad-page.h"
#include "ml3-pedal-page.h"
#include "ml3-pitch-mod-page.h"
#include "ml3-preset-page.h"
#include "ml3-preset-selected-page.h"
#include "ml3-presets-page.h"
#include "ml3-spm-page.h"
#include "ml3-velocity-page.h"

struct _Ml3Book
{
  ArBook parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml3Book, ml3_book, AR_TYPE_BOOK)

static void
ml3_book_class_init (Ml3BookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab3/ml3-book.ui");
}

// map 'show preset' into the preset space, for easy display on the preset page 
const remap_t ml3_remap[] = {
  {0x03407f7f, 0x08401300},
  {0x04407f7f, 0x08401400},
  {0x05407f7f, 0x08401500},
  {0x06407f7f, 0x08401600},
  {0x07407f7f, 0x08401700},
  {0x0, 0x0}, // sentinel
};

static void
ml3_book_init (Ml3Book *self)
{
  ArBookClass *scklass = AR_BOOK_GET_CLASS (self);
  scklass->read_control = sc_midi_arturia_v3_read_control;
  scklass->write_control = sc_midi_arturia_v3_write_control;

  ar_book_set_remap (AR_BOOK (self), ml3_remap);

  g_type_ensure (ML3_TYPE_CONTROLLER_PAGE);
  g_type_ensure (ML3_TYPE_FADER);
  g_type_ensure (ML3_TYPE_FADER_PAGE);
  g_type_ensure (ML3_TYPE_KNOB);
  g_type_ensure (ML3_TYPE_KNOB_PAGE);
  g_type_ensure (ML3_TYPE_MAIN_KNOB);
  g_type_ensure (ML3_TYPE_MAIN_KNOB_CLICK);
  g_type_ensure (ML3_TYPE_MAIN_KNOB_PAGE);
  g_type_ensure (ML3_TYPE_PAD);
  g_type_ensure (ML3_TYPE_PAD_PAGE);
  g_type_ensure (ML3_TYPE_PEDAL_PAGE);
  g_type_ensure (ML3_TYPE_PITCH_MOD_PAGE);
  g_type_ensure (ML3_TYPE_PRESET_PAGE);
  g_type_ensure (ML3_TYPE_PRESET_SELECTED_PAGE);
  g_type_ensure (ML3_TYPE_PRESETS_PAGE);
  g_type_ensure (ML3_TYPE_SPM_PAGE);
  g_type_ensure (ML3_TYPE_VELOCITY_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}
