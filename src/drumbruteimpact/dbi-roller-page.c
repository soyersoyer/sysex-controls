#include "dbi-roller-page.h"

struct _DbiRollerPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (DbiRollerPage, dbi_roller_page, SC_TYPE_NAVIGATION_PAGE)

static void
dbi_roller_page_class_init (DbiRollerPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/drumbruteimpact/dbi-roller-page.ui");
}

static void
dbi_roller_page_init (DbiRollerPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
