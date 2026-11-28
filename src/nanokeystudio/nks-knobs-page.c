#include "nks-knobs-page.h"

struct _NksKnobsPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (NksKnobsPage, nks_knobs_page, SC_TYPE_NAVIGATION_PAGE)

static void
nks_knobs_page_class_init (NksKnobsPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokeystudio/nks-knobs-page.ui");
}

static void
nks_knobs_page_init (NksKnobsPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
