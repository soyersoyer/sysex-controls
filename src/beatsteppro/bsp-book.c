#include "bsp-book.h"

#include "bsp-controller-page.h"
#include "bsp-cv-gate-page.h"
#include "bsp-drum-group.h"
#include "bsp-drum-map-page.h"
#include "bsp-metronome-page.h"
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
  g_type_ensure(BSP_TYPE_CONTROLLER_PAGE);
  g_type_ensure(BSP_TYPE_CV_GATE_PAGE);
  g_type_ensure(BSP_TYPE_DRUM_GROUP);
  g_type_ensure(BSP_TYPE_DRUM_MAP_PAGE);
  g_type_ensure(BSP_TYPE_METRONOME_PAGE);
  g_type_ensure(BSP_TYPE_SYNC_PAGE);
  g_type_ensure(BSP_TYPE_TOUCH_STRIP_PAGE);
  g_type_ensure(BSP_TYPE_TRANSPORT_PAGE);
  g_type_ensure(BSP_TYPE_TRANSPOSITION_PAGE);
  g_type_ensure(BSP_TYPE_USER_SCALE_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}
