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
  g_type_ensure (ML3_TYPE_PRESET_SELECTED_PAGE);
  g_type_ensure (ML3_TYPE_PRESETS_PAGE);
  g_type_ensure (ML3_TYPE_SPM_PAGE);
  g_type_ensure (ML3_TYPE_VELOCITY_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}

static uint32_t
get_preset_offset (ScNavigationPage *self)
{
  // 0x08400100 -> 0x04400000
  uint32_t offset = sc_navigation_page_get_control_id_offset (self);
  return 0x03400000 + (offset << 16);
}

void
sc_action_ml3_preset_nav_push (ScActionRow *row, ScNavigationPage *page)
{
  GType target_page = sc_action_row_get_target_page (row);
  const char* title = adw_preferences_row_get_title (ADW_PREFERENCES_ROW (row));
  uint32_t control_id_offset = get_preset_offset (page) + sc_action_row_get_control_id_offset (row);
  uint32_t control_cc_offset = get_preset_offset (page) + sc_action_row_get_control_cc_offset (row);
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (page), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *nav_page = g_object_new (target_page,
                                              "title", title,
                                              "control-id-offset", control_id_offset,
                                              "control-cc-offset", control_cc_offset,
                                              NULL);
  adw_navigation_view_push (view, nav_page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), nav_page);
}
