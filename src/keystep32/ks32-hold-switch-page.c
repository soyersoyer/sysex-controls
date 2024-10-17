#include "ks32-hold-switch-page.h"

struct _Ks32HoldSwitchPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ks32HoldSwitchPage, ks32_hold_switch_page, SC_TYPE_NAVIGATION_PAGE)

static void
ks32_hold_switch_page_class_init (Ks32HoldSwitchPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keystep32/ks32-hold-switch-page.ui");
}

static void
ks32_hold_switch_page_init (Ks32HoldSwitchPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
