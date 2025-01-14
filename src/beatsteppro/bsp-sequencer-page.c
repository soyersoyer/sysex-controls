#include "bsp-sequencer-page.h"

struct _BspSequencerPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (BspSequencerPage, bsp_sequencer_page, SC_TYPE_NAVIGATION_PAGE)

static void
bsp_sequencer_page_class_init (BspSequencerPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/beatsteppro/bsp-sequencer-page.ui");
}

static void
bsp_sequencer_page_init (BspSequencerPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
