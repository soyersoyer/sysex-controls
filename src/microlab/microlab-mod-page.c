#include "microlab-mod-page.h"

struct _MicrolabModPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (MicrolabModPage, microlab_mod_page, SC_TYPE_NAVIGATION_PAGE)

static void
microlab_mod_page_class_init (MicrolabModPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/microlab/microlab-mod-page.ui");
}

static void
microlab_mod_page_init (MicrolabModPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
