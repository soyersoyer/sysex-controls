#include "ml2-pad-page.h"

struct _Ml2PadPage
{
  ScPreferencesPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml2PadPage, ml2_pad_page, SC_TYPE_PREFERENCES_PAGE)

static void
ml2_pad_page_class_init (Ml2PadPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab2/ml2-pad-page.ui");
}

static void
ml2_pad_page_init (Ml2PadPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
