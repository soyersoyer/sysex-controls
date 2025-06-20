#include "ml2-book.h"

#include "ml2-button.h"
#include "ml2-controller-page.h"
#include "ml2-knob.h"
#include "ml2-knob-extra-page.h"
#include "ml2-knob-page.h"
#include "ml2-pad.h"
#include "ml2-pad-page.h"
#include "ml2-pedal-page.h"
#include "ml2-pitch-mod-page.h"
#include "ml2-preset-page.h"
#include "ml2-presets-page.h"
#include "ml2-velocity-page.h"

struct _Ml2Book
{
  ArBook parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml2Book, ml2_book, AR_TYPE_BOOK)

static void
ml2_book_class_init (Ml2BookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab2/ml2-book.ui");
}

static void
ml2_book_init (Ml2Book *self)
{
  g_type_ensure (ML2_TYPE_BUTTON);
  g_type_ensure (ML2_TYPE_CONTROLLER_PAGE);
  g_type_ensure (ML2_TYPE_KNOB);
  g_type_ensure (ML2_TYPE_KNOB_EXTRA_PAGE);
  g_type_ensure (ML2_TYPE_KNOB_PAGE);
  g_type_ensure (ML2_TYPE_PAD);
  g_type_ensure (ML2_TYPE_PAD_PAGE);
  g_type_ensure (ML2_TYPE_PEDAL_PAGE);
  g_type_ensure (ML2_TYPE_PITCH_MOD_PAGE);
  g_type_ensure (ML2_TYPE_PRESET_PAGE);
  g_type_ensure (ML2_TYPE_PRESETS_PAGE);
  g_type_ensure (ML2_TYPE_VELOCITY_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}
