#include "nks-button-page.h"

struct _NksButtonPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (NksButtonPage, nks_button_page, SC_TYPE_NAVIGATION_PAGE)

static void
nks_button_page_class_init (NksButtonPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokeystudio/nks-button-page.ui");
}

static void
nks_button_page_init (NksButtonPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
