#include "sc-note-row.h"

struct _ScNoteRow
{
  ScComboRow parent_instance;
};

G_DEFINE_FINAL_TYPE (ScNoteRow, sc_note_row, SC_TYPE_COMBO_ROW)

static void
sc_note_row_class_init (ScNoteRowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/sc-note-row.ui");
}

static void
sc_note_row_init (ScNoteRow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
