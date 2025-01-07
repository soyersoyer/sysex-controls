#include "mb2s-sequence-page.h"

struct _Mb2sSequencePage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Mb2sSequencePage, mb2s_sequence_page, SC_TYPE_NAVIGATION_PAGE)

static void
mb2s_sequence_page_class_init (Mb2sSequencePageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minibrute2s/mb2s-sequence-page.ui");
}

static void
mb2s_sequence_page_init (Mb2sSequencePage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
