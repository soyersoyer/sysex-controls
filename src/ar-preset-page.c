#include "ar-preset-page.h"

#include "sc-arturia-book.h"
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

struct _ArPresetPage
{
  ScNavigationPage parent_instance;
  uint8_t presets_num;
  uint8_t readonly_num;
};

G_DEFINE_FINAL_TYPE (ArPresetPage, ar_preset_page, SC_TYPE_NAVIGATION_PAGE)

uint8_t
ar_preset_page_get_presets_num (ArPresetPage *self)
{
  return self->presets_num;
}

uint8_t
ar_preset_page_get_readonly_num (ArPresetPage *self)
{
  return self->readonly_num;
}

static void on_selected_recall (ArPresetPage *self, ArPresetChooserRow *row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  ScArturiaBook *book = SC_ARTURIA_BOOK (gtk_widget_get_ancestor (GTK_WIDGET (self), SC_TYPE_ARTURIA_BOOK));
  ScWindow *window = SC_WINDOW (gtk_widget_get_ancestor (GTK_WIDGET (self), SC_TYPE_WINDOW));
  uint8_t preset_id = ar_preset_chooser_row_get_preset_id (row);
  g_debug ("on_selected_recall selected preset_id: %d", preset_id);
  if (sc_arturia_book_recall_preset (book, preset_id) == 0)
  {
    adw_navigation_view_pop (view);
    sc_window_load_page (window, "list");
    return;
  }
  else
  {
    sc_io_problem (window, "Preset recall failed");
    return;
  }
}

static void on_selected_store (ArPresetPage *self, ArPresetChooserRow *row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  ScArturiaBook *book = SC_ARTURIA_BOOK (gtk_widget_get_ancestor (GTK_WIDGET (self), SC_TYPE_ARTURIA_BOOK));
  ScWindow *window = SC_WINDOW (gtk_widget_get_ancestor (GTK_WIDGET (self), SC_TYPE_WINDOW));
  uint8_t preset_id = ar_preset_chooser_row_get_preset_id (row);
  g_debug ("on_selected_store selected preset_id: %d", preset_id);
  if (sc_arturia_book_store_preset (book, preset_id) != 0)
  {
    sc_io_problem (window, "Preset store failed");
    return;
  }
  adw_navigation_view_pop (view);
}

void on_recall_activated (ArPresetPage *self, AdwActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *preset_list = ADW_NAVIGATION_PAGE (ar_preset_chooser_page_new (self->presets_num, 0, on_selected_recall, self));
  adw_navigation_view_push (view, preset_list);
}

void on_store_activated (ArPresetPage *self, AdwActionRow* row)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *preset_list = ADW_NAVIGATION_PAGE (ar_preset_chooser_page_new (self->presets_num, self->readonly_num, on_selected_store, self));
  adw_navigation_view_push (view, preset_list);
}

static void
ar_preset_page_get_property (GObject    *object,
                             guint       prop_id,
                             GValue     *value,
                             GParamSpec *pspec)
{
  ArPresetPage *self = AR_PRESET_PAGE (object);

  switch (prop_id)
    {
      case PROP_PRESETS_NUM:
        g_value_set_uint (value, ar_preset_page_get_presets_num (self));
      break;
      case PROP_READONLY_NUM:
        g_value_set_uint (value, ar_preset_page_get_readonly_num (self));
      break;
      default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}


static void
ar_preset_page_set_property (GObject      *object,
                             guint         prop_id,
                             const GValue *value,
                             GParamSpec   *pspec)
{
  ArPresetPage *self = AR_PRESET_PAGE (object);

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
ar_preset_page_class_init (ArPresetPageClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->get_property = ar_preset_page_get_property;
  object_class->set_property = ar_preset_page_set_property;

  value_props[PROP_PRESETS_NUM] = g_param_spec_uint ("presets-num", NULL, NULL,
                                                     0, G_MAXUINT8, 16,
                                                     G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY);

  value_props[PROP_READONLY_NUM] = g_param_spec_uint ("readonly-num", NULL, NULL,
                                                     0, G_MAXUINT8, 0,
                                                     G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY);

  g_object_class_install_properties (object_class, LAST_PROP, value_props);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/ar-preset-page.ui");
}

static void
ar_preset_page_init (ArPresetPage *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
