#include "sple-book.h"

#include "sple-controller-page.h"
#include "sple-velocity-page.h"

struct _SpleBook
{
  ArBook parent_instance;
};

G_DEFINE_FINAL_TYPE (SpleBook, sple_book, AR_TYPE_BOOK)

static void
sple_book_class_init (SpleBookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/sparkle/sple-book.ui");
}

static void
sple_book_init (SpleBook *self)
{
  g_type_ensure (SPLE_TYPE_CONTROLLER_PAGE);
  g_type_ensure (SPLE_TYPE_VELOCITY_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}
