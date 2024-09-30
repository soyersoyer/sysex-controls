#include "sc-preferences-page.h"

enum {
  PROP_0,
  PROP_CONTROL_ID_OFFSET,
  LAST_PROP,
};

static GParamSpec *value_props[LAST_PROP];

typedef struct
{
  uint16_t control_id_offset;
} ScPreferencesPagePrivate;


G_DEFINE_TYPE_WITH_PRIVATE (ScPreferencesPage, sc_preferences_page, ADW_TYPE_PREFERENCES_PAGE)

uint16_t
sc_preferences_page_get_control_id_offset (ScPreferencesPage *self)
{
  ScPreferencesPagePrivate *priv = sc_preferences_page_get_instance_private (self);
  return priv->control_id_offset;
}

static void
sc_preferences_page_get_property (GObject    *object,
                                  guint       prop_id,
                                  GValue     *value,
                                  GParamSpec *pspec)
{
  ScPreferencesPage *self = SC_PREFERENCES_PAGE (object);

  switch (prop_id)
    {
      case PROP_CONTROL_ID_OFFSET:
        g_value_set_uint (value, sc_preferences_page_get_control_id_offset (self));
      break;
      default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}


static void
sc_preferences_page_set_property (GObject      *object,
                                  guint         prop_id,
                                  const GValue *value,
                                  GParamSpec   *pspec)
{
  ScPreferencesPage *self = SC_PREFERENCES_PAGE (object);
  ScPreferencesPagePrivate *priv = sc_preferences_page_get_instance_private (self);

  switch (prop_id)
    {
    case PROP_CONTROL_ID_OFFSET:
      priv->control_id_offset = g_value_get_uint (value);
    break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}


static void
sc_preferences_page_class_init (ScPreferencesPageClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->get_property = sc_preferences_page_get_property;
  object_class->set_property = sc_preferences_page_set_property;

  value_props[PROP_CONTROL_ID_OFFSET] = g_param_spec_uint ("control-id-offset", NULL, NULL,
                                                           0, G_MAXUINT16, 0,
                                                           G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY);

  g_object_class_install_properties (object_class, LAST_PROP, value_props);
}

static void
sc_preferences_page_init (ScPreferencesPage *self)
{
}

