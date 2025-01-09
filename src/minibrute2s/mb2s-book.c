#include "mb2s-book.h"

#include "mb2s-controller-page.h"
#include "mb2s-cv-gate-page.h"
#include "mb2s-mod-pitch-page.h"
#include "mb2s-sequence-page.h"
#include "mb2s-transport-page.h"
#include "mb2s-transposition-page.h"
#include "mb2s-user-scale-page.h"

struct _Mb2sBook
{
  ArBook parent_instance;
};

G_DEFINE_FINAL_TYPE (Mb2sBook, mb2s_book, AR_TYPE_BOOK)

static void
mb2s_book_class_init (Mb2sBookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minibrute2s/mb2s-book.ui");
}

static void
mb2s_book_init (Mb2sBook *self)
{
  g_type_ensure (MB2S_TYPE_CONTROLLER_PAGE);
  g_type_ensure (MB2S_TYPE_CV_GATE_PAGE);
  g_type_ensure (MB2S_TYPE_MOD_PITCH_PAGE);
  g_type_ensure (MB2S_TYPE_SEQUENCE_PAGE);
  g_type_ensure (MB2S_TYPE_TRANSPORT_PAGE);
  g_type_ensure (MB2S_TYPE_TRANSPOSITION_PAGE);
  g_type_ensure (MB2S_TYPE_USER_SCALE_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}
