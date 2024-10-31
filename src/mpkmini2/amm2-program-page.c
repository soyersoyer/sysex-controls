#include "amm2-program-page.h"

struct _Amm2ProgramPage
{
  AkProgramPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Amm2ProgramPage, amm2_program_page, AK_TYPE_PROGRAM_PAGE)

static void
amm2_program_page_class_init (Amm2ProgramPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/mpkmini2/amm2-program-page.ui");
}

static void
amm2_program_page_init (Amm2ProgramPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
