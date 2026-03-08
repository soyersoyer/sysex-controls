#include "np1-book.h"

#include "np1-global-page.h"
#include "np1-pad-page.h"
#include "np1-scene-page.h"
#include "np1-scenes-page.h"
#include "np1-xy-axis.h"
#include "np1-xy-pad-page.h"

struct _Np1Book
{
  KorgBook parent_instance;
};

G_DEFINE_FINAL_TYPE (Np1Book, np1_book, KORG_TYPE_BOOK)

static void
np1_book_class_init (Np1BookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanopad1/np1-book.ui");
}

static void
np1_book_init (Np1Book *self)
{
  const uint8_t np1_dev_id[4] ={0x00, 0x01, 0x03, 0x00};
  korg_book_set_dev_id (KORG_BOOK (self), np1_dev_id);

  g_type_ensure (NP1_TYPE_GLOBAL_PAGE);
  g_type_ensure (NP1_TYPE_PAD_PAGE);
  g_type_ensure (NP1_TYPE_SCENE_PAGE);
  g_type_ensure (NP1_TYPE_SCENES_PAGE);
  g_type_ensure (NP1_TYPE_XY_AXIS);
  g_type_ensure (NP1_TYPE_XY_PAD_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}
