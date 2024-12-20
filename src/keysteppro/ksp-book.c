#include "ksp-book.h"

#include "ksp-controller-page.h"
#include "ksp-cv-drum-gate.h"
#include "ksp-cv-gate-page.h"
#include "ksp-cv-voice.h"
#include "ksp-drum-map-page.h"
#include "ksp-knob.h"
#include "ksp-knob-page.h"
#include "ksp-launch-quantize-page.h"
#include "ksp-metronome-page.h"
#include "ksp-sync-page.h"
#include "ksp-touch-strip-page.h"
#include "ksp-track-channel-page.h"

struct _KspBook
{
  ArBook parent_instance;
};

G_DEFINE_FINAL_TYPE (KspBook, ksp_book, AR_TYPE_BOOK)

static void
ksp_book_class_init (KspBookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keysteppro/ksp-book.ui");
}

static void
ksp_book_init (KspBook *self)
{
  ar_book_set_read_ack (AR_BOOK (self), true);

  g_type_ensure (KSP_TYPE_CONTROLLER_PAGE);
  g_type_ensure (KSP_TYPE_CV_DRUM_GATE);
  g_type_ensure (KSP_TYPE_CV_GATE_PAGE);
  g_type_ensure (KSP_TYPE_CV_VOICE);
  g_type_ensure (KSP_TYPE_DRUM_MAP_PAGE);
  g_type_ensure (KSP_TYPE_KNOB);
  g_type_ensure (KSP_TYPE_KNOB_PAGE);
  g_type_ensure (KSP_TYPE_LAUNCH_QUANTIZE_PAGE);
  g_type_ensure (KSP_TYPE_METRONOME_PAGE);
  g_type_ensure (KSP_TYPE_SYNC_PAGE);
  g_type_ensure (KSP_TYPE_TOUCH_STRIP_PAGE);
  g_type_ensure (KSP_TYPE_TRACK_CHANNEL_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}

GtkWidget *
ksp_book_new (void)
{
  return g_object_new (KSP_TYPE_BOOK, NULL);
}
