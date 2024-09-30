#include "ks37-page-controller.h"
#include "sc-control-value.h"
#include "sc-combo-row.h"
#include "sc-midi-connect.h"

struct _Ks37PageController
{
  ScPreferencesPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ks37PageController, ks37_page_controller, SC_TYPE_PREFERENCES_PAGE)

static void
ks37_page_controller_class_init (Ks37PageControllerClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keystep37/ks37-page-controller.ui");
}

static void
ks37_page_controller_init (Ks37PageController *self)
{
  g_type_ensure (SC_TYPE_CONTROL_VALUE);
  g_type_ensure (SC_TYPE_CONTROL_VALUE_LIST);
  g_type_ensure (SC_TYPE_COMBO_ROW);
  g_type_ensure (SC_TYPE_MIDI_CONNECT);

  gtk_widget_init_template (GTK_WIDGET (self));
}


