#include "nks-scenes-page.h"

struct _NksScenesPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (NksScenesPage, nks_scenes_page, SC_TYPE_NAVIGATION_PAGE)

static void
nks_scenes_page_class_init (NksScenesPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokeystudio/nks-scenes-page.ui");
}

static void
nks_scenes_page_init (NksScenesPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
