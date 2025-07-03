#include "mpd218-knob-page.h"

struct _Mpd218KnobPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Mpd218KnobPage, mpd218_knob_page, SC_TYPE_NAVIGATION_PAGE)

static void
mpd218_knob_page_class_init (Mpd218KnobPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/mpd218/mpd218-knob-page.ui");
}

static void
mpd218_knob_page_init (Mpd218KnobPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
