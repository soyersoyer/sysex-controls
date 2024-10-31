#include "amm3-program-page.h"

struct _Amm3ProgramPage
{
  AkProgramPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Amm3ProgramPage, amm3_program_page, AK_TYPE_PROGRAM_PAGE)

static void
amm3_program_page_class_init (Amm3ProgramPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/mpkmini3/amm3-program-page.ui");
}

static void
amm3_program_page_init (Amm3ProgramPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
