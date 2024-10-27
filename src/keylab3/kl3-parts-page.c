#include "kl3-parts-page.h"

#include "kl3-part-page.h"

struct _Kl3PartsPage
{
  ScNavigationPage parent_instance;
};

G_DEFINE_FINAL_TYPE (Kl3PartsPage, kl3_parts_page, SC_TYPE_NAVIGATION_PAGE)

static void
kl3_parts_page_class_init (Kl3PartsPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/keylab3/kl3-parts-page.ui");
}

static void
kl3_parts_page_init (Kl3PartsPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}

void
kl3_parts_page_on_part_activated (Kl3PartsPage *self, ScActionRow *row)
{
  uint32_t control_id_offset = sc_navigation_page_get_control_id_offset (SC_NAVIGATION_PAGE (self)) + sc_action_row_get_control_id_offset (row);
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *page = g_object_new (KL3_TYPE_PART_PAGE,
                                          "title", adw_preferences_row_get_title (ADW_PREFERENCES_ROW (row)),
                                          "control-id-offset", control_id_offset, NULL);
  adw_navigation_view_push (view, page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), page);
}
