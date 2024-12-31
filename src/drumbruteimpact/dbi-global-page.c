#include "dbi-global-page.h"

struct _DbiGlobalPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (DbiGlobalPage, dbi_global_page, SC_TYPE_NAVIGATION_PAGE)

static void
dbi_global_page_class_init (DbiGlobalPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/drumbruteimpact/dbi-global-page.ui");
}

static void
dbi_global_page_init (DbiGlobalPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
