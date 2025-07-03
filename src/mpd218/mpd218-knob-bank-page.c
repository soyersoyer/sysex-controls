#include "mpd218-knob-bank-page.h"

struct _Mpd218KnobBankPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Mpd218KnobBankPage, mpd218_knob_bank_page, SC_TYPE_NAVIGATION_PAGE)

static void
mpd218_knob_bank_page_class_init (Mpd218KnobBankPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/mpd218/mpd218-knob-bank-page.ui");
}

static void
mpd218_knob_bank_page_init (Mpd218KnobBankPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
