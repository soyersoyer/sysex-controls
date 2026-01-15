#include "np2-scenes-page.h"

struct _Np2ScenesPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Np2ScenesPage, np2_scenes_page, SC_TYPE_NAVIGATION_PAGE)

static void
np2_scenes_page_class_init (Np2ScenesPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanopad2/np2-scenes-page.ui");
}

static void
np2_scenes_page_init (Np2ScenesPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
