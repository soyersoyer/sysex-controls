#include "nks-trigger-pads-page.h"

struct _NksTriggerPadsPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (NksTriggerPadsPage, nks_trigger_pads_page, SC_TYPE_NAVIGATION_PAGE)

static void
nks_trigger_pads_page_class_init (NksTriggerPadsPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokeystudio/nks-trigger-pads-page.ui");
}

static void
nks_trigger_pads_page_init (NksTriggerPadsPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
