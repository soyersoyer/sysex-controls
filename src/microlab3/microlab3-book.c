#include "microlab3-book.h"

#include "microlab3-controller-page.h"
#include "microlab3-keyboard-page.h"
#include "microlab3-pedal-page.h"
#include "microlab3-pitch-mod-page.h"

struct _Microlab3Book
{
  ArBook parent_instance;
};

G_DEFINE_FINAL_TYPE (Microlab3Book, microlab3_book, AR_TYPE_BOOK)

static void
microlab3_book_class_init (Microlab3BookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/microlab3/microlab3-book.ui");
}

static void
microlab3_book_init (Microlab3Book *self)
{
  ArBookClass *scklass = AR_BOOK_GET_CLASS (self);
  scklass->read_control = sc_midi_arturia_v3_read_control;
  scklass->write_control = sc_midi_arturia_v3_write_control;

  g_type_ensure (MICROLAB3_TYPE_CONTROLLER_PAGE);
  g_type_ensure (MICROLAB3_TYPE_KEYBOARD_PAGE);
  g_type_ensure (MICROLAB3_TYPE_PEDAL_PAGE);
  g_type_ensure (MICROLAB3_TYPE_PITCH_MOD_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}
