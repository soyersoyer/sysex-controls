#include "amm-program-page.h"

struct _AmmProgramPage
{
  AkProgramPage parent_instance;
};

G_DEFINE_FINAL_TYPE (AmmProgramPage, amm_program_page, AK_TYPE_PROGRAM_PAGE)

static void
amm_program_page_class_init (AmmProgramPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/mpkmini/amm-program-page.ui");
}

static void
amm_program_page_init (AmmProgramPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
