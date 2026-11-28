#include "nks-scene-keyboard-page.h"

struct _NksSceneKeyboardPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (NksSceneKeyboardPage, nks_scene_keyboard_page, SC_TYPE_NAVIGATION_PAGE)

static void
nks_scene_keyboard_page_class_init (NksSceneKeyboardPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/nanokeystudio/nks-scene-keyboard-page.ui");
}

static void
nks_scene_keyboard_page_init (NksSceneKeyboardPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
