#include "bsp-transposition-page.h"

struct _BspTranspositionPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (BspTranspositionPage, bsp_transposition_page, SC_TYPE_NAVIGATION_PAGE)

static void
bsp_transposition_page_class_init (BspTranspositionPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatsteppro/bsp-transposition-page.ui");
}

static void
bsp_transposition_page_init (BspTranspositionPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
