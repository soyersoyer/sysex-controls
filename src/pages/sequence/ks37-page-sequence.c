#include "ks37-page-sequence.h"

#include "ks37-midi.h"

struct _Ks37PageSequence
{
	Ks37PreferencesPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Ks37PageSequence, ks37_page_sequence, KS37_TYPE_PREFERENCES_PAGE)

static void
ks37_page_sequence_class_init (Ks37PageSequenceClass *klass)
{
	GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

	gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/keystep37-settings/pages/sequence/ks37-page-sequence.ui");
}

static void
ks37_page_sequence_init (Ks37PageSequence *self)
{
	gtk_widget_init_template (GTK_WIDGET (self));
}

