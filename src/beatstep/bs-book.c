#include "bs-book.h"

#include "bs-controller-page.h"
#include "bs-knob.h"
#include "bs-knob-page.h"
#include "bs-pad.h"
#include "bs-pad-page.h"
#include "bs-performance-page.h"
#include "bs-sequence-page.h"
#include "bs-transport-button.h"
#include "bs-transport-button-page.h"

struct _BsBook
{
  ArBook parent_instance;
};

G_DEFINE_FINAL_TYPE (BsBook, bs_book, AR_TYPE_BOOK)

static void
bs_book_class_init (BsBookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatstep/bs-book.ui");
}

static void
bs_book_init (BsBook *self)
{
  g_type_ensure(BS_TYPE_CONTROLLER_PAGE);
  g_type_ensure(BS_TYPE_KNOB);
  g_type_ensure(BS_TYPE_KNOB_PAGE);
  g_type_ensure(BS_TYPE_PAD);
  g_type_ensure(BS_TYPE_PAD_PAGE);
  g_type_ensure(BS_TYPE_PERFORMANCE_PAGE);
  g_type_ensure(BS_TYPE_SEQUENCE_PAGE);
  g_type_ensure(BS_TYPE_TRANSPORT_BUTTON);
  g_type_ensure(BS_TYPE_TRANSPORT_BUTTON_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}

GtkWidget *
bs_book_new (void)
{
  return g_object_new (BS_TYPE_BOOK, NULL);
}
