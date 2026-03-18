#include "nk1-cc-mode-page.h"

struct _Nk1CcModePage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Nk1CcModePage, nk1_cc_mode_page, SC_TYPE_NAVIGATION_PAGE)

static void
nk1_cc_mode_page_class_init (Nk1CcModePageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokey1/nk1-cc-mode-page.ui");
}

static void
nk1_cc_mode_page_init (Nk1CcModePage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
