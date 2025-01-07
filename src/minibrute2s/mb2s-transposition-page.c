#include "mb2s-transposition-page.h"

struct _Mb2sTranspositionPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Mb2sTranspositionPage, mb2s_transposition_page, SC_TYPE_NAVIGATION_PAGE)

static void
mb2s_transposition_page_class_init (Mb2sTranspositionPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minibrute2s/mb2s-transposition-page.ui");
}

static void
mb2s_transposition_page_init (Mb2sTranspositionPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
