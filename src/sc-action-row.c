#include "sc-action-row.h"

enum {
  PROP_0,
  PROP_CONTROL_ID_OFFSET,
  PROP_CONTROL_CC_OFFSET,
  LAST_PROP,
};

static GParamSpec *value_props[LAST_PROP];

struct _ScActionRow
{
  AdwActionRow parent_instance;
  uint32_t control_id_offset;
  uint32_t control_cc_offset;
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

  g_object_class_install_properties (object_class, LAST_PROP, value_props);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/sc-action-row.ui");
}

static void
sc_action_row_init (ScActionRow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
