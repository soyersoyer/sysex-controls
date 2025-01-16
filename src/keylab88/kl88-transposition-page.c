#include "kl88-transposition-page.h"

struct _Kl88TranspositionPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl88TranspositionPage, kl88_transposition_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl88_transposition_page_class_init (Kl88TranspositionPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab88/kl88-transposition-page.ui");
}

static void
kl88_transposition_page_init (Kl88TranspositionPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
