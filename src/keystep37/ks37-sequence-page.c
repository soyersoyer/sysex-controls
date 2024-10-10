#include "ks37-sequence-page.h"

struct _Ks37SequencePage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ks37SequencePage, ks37_sequence_page, SC_TYPE_NAVIGATION_PAGE)

static void
ks37_sequence_page_class_init (Ks37SequencePageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keystep37/ks37-sequence-page.ui");
}

static void
ks37_sequence_page_init (Ks37SequencePage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
