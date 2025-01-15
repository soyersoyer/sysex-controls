#include "kl2-book.h"

#include "kl2-bank-page.h"
#include "kl2-controller-page.h"
#include "kl2-cv-mod.h"
#include "kl2-cv-page.h"
#include "kl2-daw-button.h"
#include "kl2-daw-button-page.h"
#include "kl2-fader.h"
#include "kl2-keyboard-page.h"
#include "kl2-kfs-page.h"
#include "kl2-knob.h"
#include "kl2-pad.h"
#include "kl2-pad-page.h"
#include "kl2-pedal.h"
#include "kl2-pedal-calibration.h"
#include "kl2-pedal-calibration-page.h"
#include "kl2-pedal-page.h"
#include "kl2-pitch-mod-page.h"
#include "kl2-preset-page.h"
#include "kl2-presets-page.h"
#include "kl2-select-button.h"
#include "kl2-velocity-page.h"

struct _Kl2Book
{
  ArBook parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl2Book, kl2_book, AR_TYPE_BOOK)

static void
kl2_book_class_init (Kl2BookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab2/kl2-book.ui");
}

static void
kl2_book_init (Kl2Book *self)
{
  ar_book_set_preset_sync (AR_BOOK (self), true);

  g_type_ensure (KL2_TYPE_BANK_PAGE);
  g_type_ensure (KL2_TYPE_CONTROLLER_PAGE);
  g_type_ensure (KL2_TYPE_CV_MOD);
  g_type_ensure (KL2_TYPE_CV_PAGE);
  g_type_ensure (KL2_TYPE_DAW_BUTTON);
  g_type_ensure (KL2_TYPE_DAW_BUTTON_PAGE);
  g_type_ensure (KL2_TYPE_FADER);
  g_type_ensure (KL2_TYPE_KEYBOARD_PAGE);
  g_type_ensure (KL2_TYPE_KFS_PAGE);
  g_type_ensure (KL2_TYPE_KNOB);
  g_type_ensure (KL2_TYPE_PAD);
  g_type_ensure (KL2_TYPE_PAD_PAGE);
  g_type_ensure (KL2_TYPE_PEDAL);
  g_type_ensure (KL2_TYPE_PEDAL_CALIBRATION);
  g_type_ensure (KL2_TYPE_PEDAL_CALIBRATION_PAGE);
  g_type_ensure (KL2_TYPE_PEDAL_PAGE);
  g_type_ensure (KL2_TYPE_PITCH_MOD_PAGE);
  g_type_ensure (KL2_TYPE_PRESET_PAGE);
  g_type_ensure (KL2_TYPE_PRESETS_PAGE);
  g_type_ensure (KL2_TYPE_SELECT_BUTTON);
  g_type_ensure (KL2_TYPE_VELOCITY_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}

static void
open_preset_page (ScNavigationPage *page, ScActionRow *row, GType type)
{
  uint32_t control_id_offset = sc_navigation_page_get_control_id_offset (page) + sc_action_row_get_control_id_offset (row);
  uint32_t control_cc_offset = sc_navigation_page_get_control_cc_offset (page) + sc_action_row_get_control_cc_offset (row);
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (page), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *nav_page = g_object_new (type,
                                          "title", adw_preferences_row_get_title (ADW_PREFERENCES_ROW (row)),
                                          "control-id-offset", control_id_offset,
                                          "control-cc-offset", control_cc_offset,
                                          NULL);
  adw_navigation_view_push (view, nav_page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), nav_page);
}

void
kl2_book_on_presets_preset_activated (ScNavigationPage *page, ScActionRow *row)
{
  open_preset_page (page, row, KL2_TYPE_PRESET_PAGE);
}

void
kl2_book_on_preset_keyboard_activated (ScNavigationPage *page, ScActionRow* row)
{
  open_preset_page (page, row, KL2_TYPE_KEYBOARD_PAGE);
}

void
kl2_book_on_preset_pitch_mod_activated (ScNavigationPage *page, ScActionRow* row)
{
  open_preset_page (page, row, KL2_TYPE_PITCH_MOD_PAGE);
}

void
kl2_book_on_preset_pedal_activated (ScNavigationPage *page, ScActionRow* row)
{
  open_preset_page (page, row, KL2_TYPE_PEDAL_PAGE);
}

void
kl2_book_on_preset_cv_activated (ScNavigationPage *page, ScActionRow* row)
{
  open_preset_page (page, row, KL2_TYPE_CV_PAGE);
}

void
kl2_book_on_preset_bank_activated (ScNavigationPage *page, ScActionRow* row)
{
  open_preset_page (page, row, KL2_TYPE_BANK_PAGE);
}

void
kl2_book_on_preset_pad_activated (ScNavigationPage *page, ScActionRow* row)
{
  open_preset_page (page, row, KL2_TYPE_PAD_PAGE);
}

void
kl2_book_on_preset_daw_buttons_activated (ScNavigationPage *page, ScActionRow* row)
{
  open_preset_page (page, row, KL2_TYPE_DAW_BUTTON_PAGE);
}

void
kl2_book_on_preset_bank_column_activated (ScNavigationPage *page, ScActionRow *row)
{
  open_preset_page (page, row, KL2_TYPE_KFS_PAGE);
}
