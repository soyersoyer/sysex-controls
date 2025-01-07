#include "mb2-sequence-page.h"

struct _Mb2SequencePage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Mb2SequencePage, mb2_sequence_page, SC_TYPE_NAVIGATION_PAGE)

static void
mb2_sequence_page_class_init (Mb2SequencePageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minibrute2/mb2-sequence-page.ui");
}

static void
mb2_sequence_page_init (Mb2SequencePage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
