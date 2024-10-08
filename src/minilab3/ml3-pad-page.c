#include "ml3-pad-page.h"

struct _Ml3PadPage
{
  ScPreferencesPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml3PadPage, ml3_pad_page, SC_TYPE_PREFERENCES_PAGE)

static void
ml3_pad_page_class_init (Ml3PadPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab3/ml3-pad-page.ui");
}

static void
ml3_pad_page_init (Ml3PadPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
