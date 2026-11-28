#include "nkls-scenes-page.h"

struct _NklsScenesPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (NklsScenesPage, nkls_scenes_page, SC_TYPE_NAVIGATION_PAGE)

static void
nkls_scenes_page_class_init (NklsScenesPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokontrolstudio/nkls-scenes-page.ui");
}

static void
nkls_scenes_page_init (NklsScenesPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
