#include "kl3-book.h"

#include "kl3-controller-page.h"
#include "kl3-display-button.h"
#include "kl3-display-button-page.h"
#include "kl3-encoder.h"
#include "kl3-encoder-page.h"
#include "kl3-fader.h"
#include "kl3-fader-page.h"
#include "kl3-keyboard-page.h"
#include "kl3-main-encoder-page.h"
#include "kl3-pad.h"
#include "kl3-pad-bank-page.h"
#include "kl3-pad-page.h"
#include "kl3-part-page.h"
#include "kl3-parts-page.h"
#include "kl3-pedal.h"
#include "kl3-pedal-page.h"
#include "kl3-preset-page.h"
#include "kl3-presets-page.h"
#include "kl3-pitch-mod-page.h"
#include "kl3-sea-page.h"
#include "kl3-velocity-page.h"

struct _Kl3Book
{
  ArBook parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl3Book, kl3_book, AR_TYPE_BOOK)

static void
kl3_book_class_init (Kl3BookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab3/kl3-book.ui");
}

static void
kl3_book_init (Kl3Book *self)
{
  ArBookClass *scklass = AR_BOOK_GET_CLASS (self);
  scklass->read_control = sc_midi_arturia_v3_read_control;
  scklass->write_control = sc_midi_arturia_v3_write_control;

  g_type_ensure (KL3_TYPE_CONTROLLER_PAGE);
  g_type_ensure (KL3_TYPE_DISPLAY_BUTTON);
  g_type_ensure (KL3_TYPE_DISPLAY_BUTTON_PAGE);
  g_type_ensure (KL3_TYPE_ENCODER);
  g_type_ensure (KL3_TYPE_ENCODER_PAGE);
  g_type_ensure (KL3_TYPE_FADER);
  g_type_ensure (KL3_TYPE_FADER_PAGE);
  g_type_ensure (KL3_TYPE_KEYBOARD_PAGE);
  g_type_ensure (KL3_TYPE_MAIN_ENCODER_PAGE);
  g_type_ensure (KL3_TYPE_PAD);
  g_type_ensure (KL3_TYPE_PAD_BANK_PAGE);
  g_type_ensure (KL3_TYPE_PAD_PAGE);
  g_type_ensure (KL3_TYPE_PART_PAGE);
  g_type_ensure (KL3_TYPE_PARTS_PAGE);
  g_type_ensure (KL3_TYPE_PEDAL);
  g_type_ensure (KL3_TYPE_PEDAL_PAGE);
  g_type_ensure (KL3_TYPE_PITCH_MOD_PAGE);
  g_type_ensure (KL3_TYPE_PRESET_PAGE);
  g_type_ensure (KL3_TYPE_PRESETS_PAGE);
  g_type_ensure (KL3_TYPE_SEA_PAGE);
  g_type_ensure (KL3_TYPE_VELOCITY_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}
