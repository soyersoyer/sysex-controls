#include "bs-sequence-page.h"

struct _BsSequencePage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (BsSequencePage, bs_sequence_page, SC_TYPE_NAVIGATION_PAGE)

static void
bs_sequence_page_class_init (BsSequencePageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatstep/bs-sequence-page.ui");
}

static void
bs_sequence_page_init (BsSequencePage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
