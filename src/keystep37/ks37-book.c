#include "ks37-book.h"

#include "ks37-note-row.h"
#include "ks37-page-cc-bank.h"
#include "ks37-page-controller.h"
#include "ks37-page-cv-gate.h"
#include "ks37-page-sequence.h"
#include "ks37-page-transport.h"

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
  g_type_ensure (KS37_TYPE_NOTE_ROW);
  g_type_ensure (KS37_TYPE_PAGE_CC_BANK);
  g_type_ensure (KS37_TYPE_PAGE_CONTROLLER);
  g_type_ensure (KS37_TYPE_PAGE_CV_GATE);
  g_type_ensure (KS37_TYPE_PAGE_SEQUENCE);
  g_type_ensure (KS37_TYPE_PAGE_TRANSPORT);

  gtk_widget_init_template (GTK_WIDGET (self));
}

GtkWidget *
ks37_book_new (void)
{
  return g_object_new (KS37_TYPE_BOOK, NULL);
}

