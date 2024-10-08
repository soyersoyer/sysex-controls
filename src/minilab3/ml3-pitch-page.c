#include "ml3-pitch-page.h"

struct _Ml3PitchPage
{
  ScPreferencesPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml3PitchPage, ml3_pitch_page, SC_TYPE_PREFERENCES_PAGE)

static void
ml3_pitch_page_class_init (Ml3PitchPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab3/ml3-pitch-page.ui");
}

static void
ml3_pitch_page_init (Ml3PitchPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
