#include "np2-book.h"

#include "np2-global-page.h"
#include "np2-pad-page.h"
#include "np2-scene-page.h"
#include "np2-xy-axis.h"
#include "np2-xy-pad-cc-page.h"
#include "np2-xy-pad-ts-page.h"

struct _Np2Book
{
  KorgBook parent_instance;
};

G_DEFINE_FINAL_TYPE (Np2Book, np2_book, KORG_TYPE_BOOK)

static void
np2_book_class_init (Np2BookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanopad2/np2-book.ui");
}

static void
np2_book_init (Np2Book *self)
{
  const uint8_t np2_dev_id[4] ={0x00, 0x01, 0x12, 0x00};
  korg_book_set_dev_id (KORG_BOOK (self), np2_dev_id);

  g_type_ensure (NP2_TYPE_GLOBAL_PAGE);
  g_type_ensure (NP2_TYPE_PAD_PAGE);
  g_type_ensure (NP2_TYPE_SCENE_PAGE);
  g_type_ensure (NP2_TYPE_XY_AXIS);
  g_type_ensure (NP2_TYPE_XY_PAD_CC_PAGE);
  g_type_ensure (NP2_TYPE_XY_PAD_TS_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}
