#include "ksp-track-channel-page.h"

struct _KspTrackChannelPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (KspTrackChannelPage, ksp_track_channel_page, SC_TYPE_NAVIGATION_PAGE)

static void
ksp_track_channel_page_class_init (KspTrackChannelPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keysteppro/ksp-track-channel-page.ui");
}

static void
ksp_track_channel_page_init (KspTrackChannelPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
