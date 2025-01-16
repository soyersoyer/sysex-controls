#include "kl88-book.h"

#include "kl88-aftertouch-page.h"
#include "kl88-controller-page.h"
#include "kl88-curve-page.h"
#include "kl88-transposition-page.h"

struct _Kl88Book
{
  ArBook parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl88Book, kl88_book, AR_TYPE_BOOK)

static void
kl88_book_class_init (Kl88BookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab88/kl88-book.ui");
}

static void
kl88_book_init (Kl88Book *self)
{
  g_type_ensure (KL88_TYPE_CONTROLLER_PAGE);
  g_type_ensure (KL88_TYPE_CURVE_PAGE);
  g_type_ensure (KL88_TYPE_AFTERTOUCH_PAGE);
  g_type_ensure (KL88_TYPE_TRANSPOSITION_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}
