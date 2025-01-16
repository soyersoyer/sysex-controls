#include "kl-book.h"

#include "kl-aftertouch-page.h"
#include "kl-controller-page.h"
#include "kl-curve-page.h"

struct _KlBook
{
  ArBook parent_instance;
};

G_DEFINE_FINAL_TYPE (KlBook, kl_book, AR_TYPE_BOOK)

static void
kl_book_class_init (KlBookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab/kl-book.ui");
}

static void
kl_book_init (KlBook *self)
{
  g_type_ensure (KL_TYPE_CONTROLLER_PAGE);
  g_type_ensure (KL_TYPE_CURVE_PAGE);
  g_type_ensure (KL_TYPE_AFTERTOUCH_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}
