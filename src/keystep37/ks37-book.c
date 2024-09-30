#include "ks37-book.h"

#include "ks37-cc-bank-page.h"
#include "ks37-controller-page.h"
#include "ks37-cv-gate-page.h"
#include "ks37-note-row.h"
#include "ks37-sequence-page.h"
#include "ks37-transport-page.h"

struct _Ks37Book
{
  AdwBin parent_instance;
};

G_DEFINE_FINAL_TYPE (Ks37Book, ks37_book, ADW_TYPE_BIN)

static void
ks37_book_class_init (Ks37BookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keystep37/ks37-book.ui");
}

static void
ks37_book_init (Ks37Book *self)
{
  g_type_ensure (KS37_TYPE_CC_BANK_PAGE);
  g_type_ensure (KS37_TYPE_CONTROLLER_PAGE);
  g_type_ensure (KS37_TYPE_CV_GATE_PAGE);
  g_type_ensure (KS37_TYPE_NOTE_ROW);
  g_type_ensure (KS37_TYPE_SEQUENCE_PAGE);
  g_type_ensure (KS37_TYPE_TRANSPORT_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}

GtkWidget *
ks37_book_new (void)
{
  return g_object_new (KS37_TYPE_BOOK, NULL);
}

