#include "microlab-book.h"

#include "microlab-hold-page.h"
#include "microlab-keyboard-page.h"
#include "microlab-mod-page.h"
#include "microlab-pitch-page.h"

struct _MicrolabBook
{
  ArBook parent_instance;
};

G_DEFINE_FINAL_TYPE (MicrolabBook, microlab_book, AR_TYPE_BOOK)

static void
microlab_book_class_init (MicrolabBookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/microlab/microlab-book.ui");
}

static void
microlab_book_init (MicrolabBook *self)
{
  g_type_ensure (MICROLAB_TYPE_HOLD_PAGE);
  g_type_ensure (MICROLAB_TYPE_KEYBOARD_PAGE);
  g_type_ensure (MICROLAB_TYPE_MOD_PAGE);
  g_type_ensure (MICROLAB_TYPE_PITCH_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}
