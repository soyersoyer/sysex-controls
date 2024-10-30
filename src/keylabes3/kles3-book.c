#include "kles3-book.h"

#include "kles3-controller-page.h"
#include "kles3-pedal-page.h"
#include "kles3-preset-page.h"
#include "kles3-velocity-page.h"

struct _Kles3Book
{
  ArBook parent_instance;
};

G_DEFINE_FINAL_TYPE (Kles3Book, kles3_book, AR_TYPE_BOOK)

static void
kles3_book_class_init (Kles3BookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes3/kles3-book.ui");
}

static void
kles3_book_init (Kles3Book *self)
{
  ArBookClass *scklass = AR_BOOK_GET_CLASS (self);
  scklass->read_control = sc_midi_arturia_v3_read_control;
  scklass->write_control = sc_midi_arturia_v3_write_control;

  g_type_ensure (KLES3_TYPE_CONTROLLER_PAGE);
  g_type_ensure (KLES3_TYPE_PEDAL_PAGE);
  g_type_ensure (KLES3_TYPE_PRESET_PAGE);
  g_type_ensure (KLES3_TYPE_VELOCITY_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}

GtkWidget *
kles3_book_new (void)
{
  return g_object_new (KLES3_TYPE_BOOK, NULL);
}
