#include "mpd218-note-repeat-page.h"

struct _Mpd218NoteRepeatPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Mpd218NoteRepeatPage, mpd218_note_repeat_page, SC_TYPE_NAVIGATION_PAGE)

static void
mpd218_note_repeat_page_class_init (Mpd218NoteRepeatPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/mpd218/mpd218-note-repeat-page.ui");
}

static void
mpd218_note_repeat_page_init (Mpd218NoteRepeatPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
