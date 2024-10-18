#include "microlab-hold-page.h"

struct _MicrolabHoldPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (MicrolabHoldPage, microlab_hold_page, SC_TYPE_NAVIGATION_PAGE)

static void
microlab_hold_page_class_init (MicrolabHoldPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/microlab/microlab-hold-page.ui");
}

static void
microlab_hold_page_init (MicrolabHoldPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
