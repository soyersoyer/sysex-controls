#include "ks37-note-row.h"

struct _Ks37NoteRow
{
  ScComboRow parent_instance;
};

G_DEFINE_FINAL_TYPE (Ks37NoteRow, ks37_note_row, SC_TYPE_COMBO_ROW)

static void
ks37_note_row_class_init (Ks37NoteRowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keystep37/ks37-note-row.ui");
}

static void
ks37_note_row_init (Ks37NoteRow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
