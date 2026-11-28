#include "nks-trigger-pad-page.h"

struct _NksTriggerPadPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (NksTriggerPadPage, nks_trigger_pad_page, SC_TYPE_NAVIGATION_PAGE)

static void
nks_trigger_pad_page_class_init (NksTriggerPadPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokeystudio/nks-trigger-pad-page.ui");
}

static void
nks_trigger_pad_page_init (NksTriggerPadPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
