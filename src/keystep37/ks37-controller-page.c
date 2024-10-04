#include "ks37-controller-page.h"

struct _Ks37ControllerPage
{
  ScPreferencesPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ks37ControllerPage, ks37_controller_page, SC_TYPE_PREFERENCES_PAGE)

static void
ks37_controller_page_class_init (Ks37ControllerPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keystep37/ks37-controller-page.ui");
}

static void
ks37_controller_page_init (Ks37ControllerPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
