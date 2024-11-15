#include "ar2-note-drop-down.h"

struct _Ar2NoteDropDown
{
  GtkBox parent_instance;
};

G_DEFINE_FINAL_TYPE (Ar2NoteDropDown, ar2_note_drop_down, GTK_TYPE_BOX)

static void
ar2_note_drop_down_class_init (Ar2NoteDropDownClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/ar2-note-drop-down.ui");
}

static int
move_childs_to_parent (GtkWidget *self)
{
  GtkBox *parent = GTK_BOX (gtk_widget_get_parent (self));
  GtkWidget *child;

  while ((child = gtk_widget_get_first_child (self))) {
    g_object_ref(child);
    gtk_box_remove (GTK_BOX (self), child);
    gtk_box_insert_child_after (GTK_BOX (parent), child, self);
    g_object_unref(child);
  }

  gtk_box_remove (parent, self);

  return 0;
}

static void
ar2_note_drop_down_init (Ar2NoteDropDown *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));

  g_idle_add (G_SOURCE_FUNC (move_childs_to_parent), self);
}
