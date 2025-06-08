#include "bs-preset-page.h"

struct _BsPresetPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (BsPresetPage, bs_preset_page, SC_TYPE_NAVIGATION_PAGE)

static void
bs_preset_page_class_init (BsPresetPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatstep/bs-preset-page.ui");
}

static void
bs_preset_page_init (BsPresetPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
