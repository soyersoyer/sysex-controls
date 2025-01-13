#include "bsp-book.h"

#include "bsp-controller-page.h"
#include "bsp-cv-gate-page.h"
#include "bsp-drum-group.h"
#include "bsp-drum-map-page.h"
#include "bsp-knob.h"
#include "bsp-knob-page.h"
#include "bsp-metronome-page.h"
#include "bsp-pad.h"
#include "bsp-pad-page.h"
#include "bsp-project-page.h"
#include "bsp-project-setting-page.h"
#include "bsp-step.h"
#include "bsp-step-page.h"
#include "bsp-sync-page.h"
#include "bsp-touch-strip-page.h"
#include "bsp-transport-page.h"
#include "bsp-transposition-page.h"
#include "bsp-user-scale-page.h"

struct _BspBook
{
  ArBook parent_instance;
};

G_DEFINE_FINAL_TYPE (BspBook, bsp_book, AR_TYPE_BOOK)

static void
bsp_book_class_init (BspBookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatsteppro/bsp-book.ui");
}

static void
bsp_book_init (BspBook *self)
{
  ar_book_set_read_ack (AR_BOOK (self), true);

  g_type_ensure(BSP_TYPE_CONTROLLER_PAGE);
  g_type_ensure(BSP_TYPE_CV_GATE_PAGE);
  g_type_ensure(BSP_TYPE_DRUM_GROUP);
  g_type_ensure(BSP_TYPE_DRUM_MAP_PAGE);
  g_type_ensure(BSP_TYPE_KNOB);
  g_type_ensure(BSP_TYPE_KNOB_PAGE);
  g_type_ensure(BSP_TYPE_METRONOME_PAGE);
  g_type_ensure(BSP_TYPE_PAD);
  g_type_ensure(BSP_TYPE_PAD_PAGE);
  g_type_ensure(BSP_TYPE_PROJECT_PAGE);
  g_type_ensure(BSP_TYPE_PROJECT_SETTING_PAGE);
  g_type_ensure(BSP_TYPE_STEP);
  g_type_ensure(BSP_TYPE_STEP_PAGE);
  g_type_ensure(BSP_TYPE_SYNC_PAGE);
  g_type_ensure(BSP_TYPE_TOUCH_STRIP_PAGE);
  g_type_ensure(BSP_TYPE_TRANSPORT_PAGE);
  g_type_ensure(BSP_TYPE_TRANSPOSITION_PAGE);
  g_type_ensure(BSP_TYPE_USER_SCALE_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}

static void
open_project_page (ScNavigationPage *page, ScActionRow *row, GType type)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (page), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *nav_page = g_object_new (type,
                                          "title", adw_preferences_row_get_title (ADW_PREFERENCES_ROW (row)),
                                          NULL);
  adw_navigation_view_push (view, nav_page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), nav_page);
}

void
bsp_book_on_project_settings_activated (ScNavigationPage *page, ScActionRow* row)
{
  open_project_page (page, row, BSP_TYPE_PROJECT_SETTING_PAGE);
}

void
bsp_book_on_project_knobs_activated (ScNavigationPage *page, ScActionRow* row)
{
  open_project_page (page, row, BSP_TYPE_KNOB_PAGE);
}

void
bsp_book_on_project_steps_activated (ScNavigationPage *page, ScActionRow* row)
{
  open_project_page (page, row, BSP_TYPE_STEP_PAGE);
}

void
bsp_book_on_project_pads_activated (ScNavigationPage *page, ScActionRow* row)
{
  open_project_page (page, row, BSP_TYPE_PAD_PAGE);
}
