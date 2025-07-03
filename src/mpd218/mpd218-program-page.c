#include "mpd218-program-page.h"

struct _Mpd218ProgramPage
{
  AkProgramPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Mpd218ProgramPage, mpd218_program_page, AK_TYPE_PROGRAM_PAGE)

static void
mpd218_program_page_class_init (Mpd218ProgramPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/mpd218/mpd218-program-page.ui");
}

static void
mpd218_program_page_init (Mpd218ProgramPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
