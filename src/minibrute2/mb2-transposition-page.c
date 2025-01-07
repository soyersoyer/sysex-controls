#include "mb2-transposition-page.h"

struct _Mb2TranspositionPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Mb2TranspositionPage, mb2_transposition_page, SC_TYPE_NAVIGATION_PAGE)

static void
mb2_transposition_page_class_init (Mb2TranspositionPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minibrute2/mb2-transposition-page.ui");
}

static void
mb2_transposition_page_init (Mb2TranspositionPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
