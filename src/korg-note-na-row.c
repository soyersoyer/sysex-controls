#include "korg-note-na-row.h"

struct _KorgNoteNaRow
{
  ScComboRow parent_instance;
};

G_DEFINE_FINAL_TYPE (KorgNoteNaRow, korg_note_na_row, SC_TYPE_COMBO_ROW)

static void
korg_note_na_row_class_init (KorgNoteNaRowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/korg-note-na-row.ui");
}

static void
korg_note_na_row_init (KorgNoteNaRow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
