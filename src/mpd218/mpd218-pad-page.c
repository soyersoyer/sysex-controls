#include "mpd218-pad-page.h"

struct _Mpd218PadPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Mpd218PadPage, mpd218_pad_page, SC_TYPE_NAVIGATION_PAGE)

static void
mpd218_pad_page_class_init (Mpd218PadPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/mpd218/mpd218-pad-page.ui");
}

static void
mpd218_pad_page_init (Mpd218PadPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
