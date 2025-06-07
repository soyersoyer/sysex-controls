#include "kles-book.h"

#include "kles-button.h"
#include "kles-button-page.h"
#include "kles-controller-page.h"
#include "kles-fader.h"
#include "kles-fader-page.h"
#include "kles-keyboard-page.h"
#include "kles-knob.h"
#include "kles-knob-page.h"
#include "kles-pad.h"
#include "kles-pad-page.h"
#include "kles-pedal-page.h"
#include "kles-preset-page.h"
#include "kles-presets-page.h"
#include "kles-velocity-page.h"

struct _KlesBook
{
  ArBook parent_instance;
};

G_DEFINE_FINAL_TYPE (KlesBook, kles_book, AR_TYPE_BOOK)

static void
kles_book_class_init (KlesBookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes/kles-book.ui");
}

static void
kles_book_init (KlesBook *self)
{
  ar_book_set_preset_sync (AR_BOOK (self), true);

  g_type_ensure (KLES_TYPE_BUTTON);
  g_type_ensure (KLES_TYPE_BUTTON_PAGE);
  g_type_ensure (KLES_TYPE_CONTROLLER_PAGE);
  g_type_ensure (KLES_TYPE_FADER);
  g_type_ensure (KLES_TYPE_FADER_PAGE);
  g_type_ensure (KLES_TYPE_KEYBOARD_PAGE);
  g_type_ensure (KLES_TYPE_KNOB);
  g_type_ensure (KLES_TYPE_KNOB_PAGE);
  g_type_ensure (KLES_TYPE_PAD);
  g_type_ensure (KLES_TYPE_PAD_PAGE);
  g_type_ensure (KLES_TYPE_PEDAL_PAGE);
  g_type_ensure (KLES_TYPE_PRESET_PAGE);
  g_type_ensure (KLES_TYPE_PRESETS_PAGE);
  g_type_ensure (KLES_TYPE_VELOCITY_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}
