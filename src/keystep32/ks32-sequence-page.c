#include "ks32-sequence-page.h"

struct _Ks32SequencePage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ks32SequencePage, ks32_sequence_page, SC_TYPE_NAVIGATION_PAGE)

static void
ks32_sequence_page_class_init (Ks32SequencePageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keystep32/ks32-sequence-page.ui");
}

static void
ks32_sequence_page_init (Ks32SequencePage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
