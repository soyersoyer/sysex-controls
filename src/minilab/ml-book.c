#include "ml-book.h"

#include "ar-preset-page.h"

#include "ml-controller-page.h"
#include "ml-knob.h"
#include "ml-knob-page.h"
#include "ml-pad.h"
#include "ml-pad-page.h"
#include "ml-pedal-page.h"
#include "ml-pitch-mod-page.h"
#include "ml-preset-page.h"
#include "ml-presets-page.h"
#include "ml-velocity-page.h"

struct _MlBook
{
  ArBook parent_instance;
};

G_DEFINE_FINAL_TYPE (MlBook, ml_book, AR_TYPE_BOOK)

static void
ml_book_class_init (MlBookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab/ml-book.ui");
}

static void
ml_book_init (MlBook *self)
{
  g_type_ensure (ML_TYPE_CONTROLLER_PAGE);
  g_type_ensure (ML_TYPE_KNOB);
  g_type_ensure (ML_TYPE_KNOB_PAGE);
  g_type_ensure (ML_TYPE_PAD);
  g_type_ensure (ML_TYPE_PAD_PAGE);
  g_type_ensure (ML_TYPE_PEDAL_PAGE);
  g_type_ensure (ML_TYPE_PITCH_MOD_PAGE);
  g_type_ensure (ML_TYPE_PRESET_PAGE);
  g_type_ensure (ML_TYPE_PRESETS_PAGE);
  g_type_ensure (ML_TYPE_VELOCITY_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}

void
ml_book_on_presets_ar_presets_activated (ScNavigationPage *page, ScActionRow *row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (page), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *nav_page = g_object_new (AR_TYPE_PRESET_PAGE,
                                          "title", adw_preferences_row_get_title (ADW_PREFERENCES_ROW (row)),
                                          "presets-num", 8,
                                          "readonly-num", 1,
                                          NULL);
  adw_navigation_view_push (view, nav_page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), nav_page);
}
