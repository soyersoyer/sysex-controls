#include "ks37-cv-gate-page.h"

struct _Ks37CvGatePage
{
  ScPreferencesPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ks37CvGatePage, ks37_cv_gate_page, SC_TYPE_PREFERENCES_PAGE)

static void
ks37_cv_gate_page_class_init (Ks37CvGatePageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keystep37/ks37-cv-gate-page.ui");
}

static void
ks37_cv_gate_page_init (Ks37CvGatePage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}

