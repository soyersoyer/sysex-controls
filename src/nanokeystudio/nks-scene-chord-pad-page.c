#include "nks-scene-chord-pad-page.h"

struct _NksSceneChordPadPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (NksSceneChordPadPage, nks_scene_chord_pad_page, SC_TYPE_NAVIGATION_PAGE)

static void
nks_scene_chord_pad_page_class_init (NksSceneChordPadPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokeystudio/nks-scene-chord-pad-page.ui");
}

static void
nks_scene_chord_pad_page_init (NksSceneChordPadPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
