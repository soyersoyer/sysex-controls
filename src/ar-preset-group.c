#include "ar-preset-group.h"

#include "ar-book.h"
#include "ar-preset-chooser-page.h"
#include "ar-preset-chooser-row.h"
#include "sc-window.h"

enum {
  PROP_0,
  PROP_PRESETS_NUM,
  PROP_READONLY_NUM,
  LAST_PROP,
};

static GParamSpec *value_props[LAST_PROP];

struct _ArPresetGroup
{
  AdwPreferencesGroup parent_instance;
  uint8_t presets_num;
  uint8_t readonly_num;
};

G_DEFINE_FINAL_TYPE (ArPresetGroup, ar_preset_group, ADW_TYPE_PREFERENCES_GROUP)

uint8_t
ar_preset_group_get_presets_num (ArPresetGroup *self)
{
  return self->presets_num;
}

uint8_t
ar_preset_group_get_readonly_num (ArPresetGroup *self)
{
  return self->readonly_num;
}

static void
on_selected_recall (ArPresetChooserRow *row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (row), ADW_TYPE_NAVIGATION_VIEW));
  ArBook *book = AR_BOOK (gtk_widget_get_ancestor (GTK_WIDGET (row), AR_TYPE_BOOK));
  AdwNavigationView *book_view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (book), ADW_TYPE_NAVIGATION_VIEW));
  ScWindow *window = SC_WINDOW (gtk_widget_get_ancestor (GTK_WIDGET (row), SC_TYPE_WINDOW));
  uint8_t preset_id = ar_preset_chooser_row_get_preset_id (row);
  g_debug ("on_selected_recall selected preset_id: %d", preset_id);
  if (ar_book_recall_preset (book, preset_id) != 0)
  {
    sc_io_problem (window, "Preset recall failed");
    return;
  }
  adw_navigation_view_push_by_tag (book_view, "load");
  adw_navigation_view_pop (view);
  g_idle_add (G_SOURCE_FUNC (sc_book_load), book);
}

static void
on_selected_store (ArPresetChooserRow *row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (row), ADW_TYPE_NAVIGATION_VIEW));
  ArBook *book = AR_BOOK (gtk_widget_get_ancestor (GTK_WIDGET (row), AR_TYPE_BOOK));
  ScWindow *window = SC_WINDOW (gtk_widget_get_ancestor (GTK_WIDGET (row), SC_TYPE_WINDOW));
  uint8_t preset_id = ar_preset_chooser_row_get_preset_id (row);
  g_debug ("on_selected_store selected preset_id: %d", preset_id);
  if (ar_book_store_preset (book, preset_id) != 0)
  {
    sc_io_problem (window, "Preset store failed");
    return;
  }
  adw_navigation_view_pop (view);
}

void ar_preset_group_on_recall_activated (ArPresetGroup *self, AdwActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *preset_list = ADW_NAVIGATION_PAGE (ar_preset_chooser_page_new (self->presets_num, 0, on_selected_recall));
  adw_navigation_page_set_title (preset_list, "Recall preset from");
  adw_navigation_view_push (view, preset_list);
}

void ar_preset_group_on_store_activated (ArPresetGroup *self, AdwActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *preset_list = ADW_NAVIGATION_PAGE (ar_preset_chooser_page_new (self->presets_num, self->readonly_num, on_selected_store));
  adw_navigation_page_set_title (preset_list, "Store preset on");
  adw_navigation_view_push (view, preset_list);
}

static void
ar_preset_group_get_property (GObject    *object,
                              guint       prop_id,
                              GValue     *value,
                              GParamSpec *pspec)
{
  ArPresetGroup *self = AR_PRESET_GROUP (object);

  switch (prop_id)
    {
      case PROP_PRESETS_NUM:
        g_value_set_uint (value, ar_preset_group_get_presets_num (self));
      break;
      case PROP_READONLY_NUM:
        g_value_set_uint (value, ar_preset_group_get_readonly_num (self));
      break;
      default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}

static void
ar_preset_group_set_property (GObject      *object,
                              guint         prop_id,
                              const GValue *value,
                              GParamSpec   *pspec)
{
  ArPresetGroup *self = AR_PRESET_GROUP (object);

  switch (prop_id)
    {
    case PROP_PRESETS_NUM:
      self->presets_num = g_value_get_uint (value);
    break;
    case PROP_READONLY_NUM:
      self->readonly_num = g_value_get_uint (value);
    break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}

static void
ar_preset_group_class_init (ArPresetGroupClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->get_property = ar_preset_group_get_property;
  object_class->set_property = ar_preset_group_set_property;

  value_props[PROP_PRESETS_NUM] = g_param_spec_uint ("presets-num", NULL, NULL,
                                                     0, G_MAXUINT8, 16,
                                                     G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY);

  value_props[PROP_READONLY_NUM] = g_param_spec_uint ("readonly-num", NULL, NULL,
                                                     0, G_MAXUINT8, 0,
                                                     G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY);

  g_object_class_install_properties (object_class, LAST_PROP, value_props);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/ar-preset-group.ui");
}

static void
ar_preset_group_init (ArPresetGroup *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
