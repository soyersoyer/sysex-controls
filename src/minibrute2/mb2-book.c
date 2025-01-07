#include "mb2-book.h"

#include "mb2-controller-page.h"
#include "mb2-cv-gate-page.h"
#include "mb2-mod-pitch-page.h"
#include "mb2-sequence-page.h"
#include "mb2-transport-page.h"
#include "mb2-transposition-page.h"

struct _Mb2Book
{
  ArBook parent_instance;
};

G_DEFINE_FINAL_TYPE (Mb2Book, mb2_book, AR_TYPE_BOOK)

static void
mb2_book_class_init (Mb2BookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minibrute2/mb2-book.ui");
}

static void
mb2_book_init (Mb2Book *self)
{
  g_type_ensure (MB2_TYPE_CONTROLLER_PAGE);
  g_type_ensure (MB2_TYPE_CV_GATE_PAGE);
  g_type_ensure (MB2_TYPE_MOD_PITCH_PAGE);
  g_type_ensure (MB2_TYPE_SEQUENCE_PAGE);
  g_type_ensure (MB2_TYPE_TRANSPORT_PAGE);
  g_type_ensure (MB2_TYPE_TRANSPOSITION_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}

GtkWidget *
mb2_book_new (void)
{
  return g_object_new (MB2_TYPE_BOOK, NULL);
}
