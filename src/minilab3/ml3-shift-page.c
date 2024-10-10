#include "ml3-shift-page.h"

struct _Ml3ShiftPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ml3ShiftPage, ml3_shift_page, SC_TYPE_NAVIGATION_PAGE)

static void
ml3_shift_page_class_init (Ml3ShiftPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab3/ml3-shift-page.ui");
}

static void
ml3_shift_page_init (Ml3ShiftPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
