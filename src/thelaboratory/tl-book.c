#include "tl-book.h"

#include "tl-aftertouch-page.h"
#include "tl-controller-page.h"
#include "tl-curve-page.h"

struct _TlBook
{
  ArBook parent_instance;
};

G_DEFINE_FINAL_TYPE (TlBook, tl_book, AR_TYPE_BOOK)

static void
tl_book_class_init (TlBookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/thelaboratory/tl-book.ui");
}

static void
tl_book_init (TlBook *self)
{
  g_type_ensure (TL_TYPE_CONTROLLER_PAGE);
  g_type_ensure (TL_TYPE_CURVE_PAGE);
  g_type_ensure (TL_TYPE_AFTERTOUCH_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}
