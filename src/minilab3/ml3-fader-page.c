#include "ml3-fader-page.h"

struct _Ml3FaderPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml3FaderPage, ml3_fader_page, SC_TYPE_NAVIGATION_PAGE)

static void
ml3_fader_page_class_init (Ml3FaderPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab3/ml3-fader-page.ui");
}

static void
ml3_fader_page_init (Ml3FaderPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
