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

static void
ml3_book_init (Ml3Book *self)
{
  ArBookClass *scklass = AR_BOOK_GET_CLASS (self);
  scklass->read_control = sc_midi_arturia_v3_read_control;
  scklass->write_control = sc_midi_arturia_v3_write_control;

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
  g_type_ensure (ML3_TYPE_SPM_PAGE);
  g_type_ensure (ML3_TYPE_VELOCITY_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}

GtkWidget *
ml3_book_new (void)
{
  return g_object_new (ML3_TYPE_BOOK, NULL);
}
