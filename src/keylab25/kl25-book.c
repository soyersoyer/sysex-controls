#include "kl25-book.h"

#include "kl25-aftertouch-page.h"
#include "kl25-controller-page.h"
#include "kl25-curve-page.h"

struct _Kl25Book
{
  ArBook parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl25Book, kl25_book, AR_TYPE_BOOK)

static void
kl25_book_class_init (Kl25BookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab25/kl25-book.ui");
}

static void
kl25_book_init (Kl25Book *self)
{
  g_type_ensure (KL25_TYPE_CONTROLLER_PAGE);
  g_type_ensure (KL25_TYPE_CURVE_PAGE);
  g_type_ensure (KL25_TYPE_AFTERTOUCH_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}
