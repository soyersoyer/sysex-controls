#include "kles3-pad-page.h"

struct _Kles3PadPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kles3PadPage, kles3_pad_page, SC_TYPE_NAVIGATION_PAGE)

static void
kles3_pad_page_class_init (Kles3PadPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylabes3/preset/kles3-pad-page.ui");
}

static void
kles3_pad_page_init (Kles3PadPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
