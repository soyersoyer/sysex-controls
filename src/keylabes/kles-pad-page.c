#include "kles-pad-page.h"

struct _KlesPadPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (KlesPadPage, kles_pad_page, SC_TYPE_NAVIGATION_PAGE)

static void
kles_pad_page_class_init (KlesPadPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes/kles-pad-page.ui");
}

static void
kles_pad_page_init (KlesPadPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
