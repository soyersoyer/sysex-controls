#include "sc-action-row.h"

enum {
  PROP_0,
  PROP_CONTROL_ID_OFFSET,
  PROP_CONTROL_CC_OFFSET,
  PROP_TARGET_PAGE,
  LAST_PROP,
};

static GParamSpec *value_props[LAST_PROP];

struct _ScActionRow
{
  AdwActionRow parent_instance;
  uint32_t control_id_offset;
  uint32_t control_cc_offset;
  GType target_page;
};

G_DEFINE_FINAL_TYPE (ScActionRow, sc_action_row, ADW_TYPE_ACTION_ROW)

uint32_t
sc_action_row_get_control_id_offset (ScActionRow *self)
{
  return self->control_id_offset;
}

uint32_t
sc_action_row_get_control_cc_offset (ScActionRow *self)
{
  return self->control_cc_offset;
}

GType
sc_action_row_get_target_page (ScActionRow *self)
{
  return self->target_page;
}

static void
sc_action_row_get_property (GObject    *object,
                            guint       prop_id,
                            GValue     *value,
                            GParamSpec *pspec)
{
  ScActionRow *self = SC_ACTION_ROW (object);

  switch (prop_id)
    {
      case PROP_CONTROL_ID_OFFSET:
        g_value_set_uint (value, sc_action_row_get_control_id_offset (self));
      break;
      case PROP_CONTROL_CC_OFFSET:
        g_value_set_uint (value, sc_action_row_get_control_cc_offset (self));
      break;
      case PROP_TARGET_PAGE:
        g_value_set_gtype (value, sc_action_row_get_target_page (self));
      break;
      default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}


static void
sc_action_row_set_property (GObject      *object,
                            guint         prop_id,
                            const GValue *value,
                            GParamSpec   *pspec)
{
  ScActionRow *self = SC_ACTION_ROW (object);

  switch (prop_id)
    {
    case PROP_CONTROL_ID_OFFSET:
      self->control_id_offset = g_value_get_uint (value);
    break;
    case PROP_CONTROL_CC_OFFSET:
      self->control_cc_offset = g_value_get_uint (value);
    break;
    case PROP_TARGET_PAGE:
      self->target_page = g_value_get_gtype (value);
    break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}


static void
sc_action_row_class_init (ScActionRowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->get_property = sc_action_row_get_property;
  object_class->set_property = sc_action_row_set_property;

  value_props[PROP_CONTROL_ID_OFFSET] = g_param_spec_uint ("control-id-offset", NULL, NULL,
                                                           0, G_MAXUINT32, 0,
                                                           G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY);

  value_props[PROP_CONTROL_CC_OFFSET] = g_param_spec_uint ("control-cc-offset", NULL, NULL,
                                                           0, G_MAXUINT32, 0,
                                                           G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY);

  value_props[PROP_TARGET_PAGE] = g_param_spec_gtype ("target-page", NULL, NULL,
                                                      G_TYPE_NONE,
                                                      G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY);

  g_object_class_install_properties (object_class, LAST_PROP, value_props);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/sc-action-row.ui");
}

static void
sc_action_row_init (ScActionRow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}

void
sc_action_nav_push (ScActionRow *row, ScNavigationPage *page)
{
  GType target_page = sc_action_row_get_target_page (row);
  const char* title = adw_preferences_row_get_title (ADW_PREFERENCES_ROW (row));
  uint32_t control_id_offset = sc_navigation_page_get_control_id_offset (page) + sc_action_row_get_control_id_offset (row);
  uint32_t control_cc_offset = sc_navigation_page_get_control_cc_offset (page) + sc_action_row_get_control_cc_offset (row);
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (page), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *nav_page = g_object_new (target_page,
                                              "title", title,
                                              "control-id-offset", control_id_offset,
                                              "control-cc-offset", control_cc_offset,
                                              NULL);
  adw_navigation_view_push (view, nav_page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), nav_page);
}
