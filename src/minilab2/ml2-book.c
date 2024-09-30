#include "ml2-book.h"

#include "sc-midi-connect.h"
#include "sc-preferences-page.h"
#include "ml2-color-row.h"

struct _Ml2Book
{
  AdwBin parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml2Book, ml2_book, ADW_TYPE_BIN)

static void
ml2_book_class_init (Ml2BookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab2/ml2-book.ui");
}

static void
ml2_book_init (Ml2Book *self)
{
  g_type_ensure (SC_TYPE_MIDI_CONNECT);
  g_type_ensure (SC_TYPE_PREFERENCES_PAGE);
  g_type_ensure (ML2_TYPE_COLOR_ROW);

  gtk_widget_init_template (GTK_WIDGET (self));
}

GtkWidget *
ml2_book_new (void)
{
  return g_object_new (ML2_TYPE_BOOK, NULL);
}

