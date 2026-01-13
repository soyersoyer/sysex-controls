#include "korg-note-offset-row.h"

struct _KorgNoteOffsetRow
{
  ScComboRow parent_instance;
};

G_DEFINE_FINAL_TYPE (KorgNoteOffsetRow, korg_note_offset_row, SC_TYPE_COMBO_ROW)

static void
korg_note_offset_row_class_init (KorgNoteOffsetRowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/korg-note-offset-row.ui");
}

static void
korg_note_offset_row_init (KorgNoteOffsetRow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
