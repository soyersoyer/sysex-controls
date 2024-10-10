#include "sc-navigation-page.h"

enum {
  PROP_0,
  PROP_CONTROL_ID_OFFSET,
  PROP_CONTROL_CC_OFFSET,
  LAST_PROP,
};

static GParamSpec *value_props[LAST_PROP];

typedef struct
{
  uint32_t control_id_offset;
  uint32_t control_cc_offset;
} ScNavigationPagePrivate;


G_DEFINE_TYPE_WITH_PRIVATE (ScNavigationPage, sc_navigation_page, ADW_TYPE_NAVIGATION_PAGE)

uint32_t
sc_navigation_page_get_control_id_offset (ScNavigationPage *self)
{
  ScNavigationPagePrivate *priv = sc_navigation_page_get_instance_private (self);
  return priv->control_id_offset;
}

uint32_t
sc_navigation_page_get_control_cc_offset (ScNavigationPage *self)
{
  ScNavigationPagePrivate *priv = sc_navigation_page_get_instance_private (self);
  return priv->control_cc_offset;
}

static void
sc_navigation_page_get_property (GObject    *object,
                                 guint       prop_id,
                                 GValue     *value,
                                 GParamSpec *pspec)
{
  ScNavigationPage *self = SC_NAVIGATION_PAGE (object);

  switch (prop_id)
    {
      case PROP_CONTROL_ID_OFFSET:
        g_value_set_uint (value, sc_navigation_page_get_control_id_offset (self));
      break;
      case PROP_CONTROL_CC_OFFSET:
        g_value_set_uint (value, sc_navigation_page_get_control_cc_offset (self));
      break;
      default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}


static void
sc_navigation_page_set_property (GObject      *object,
                                 guint         prop_id,
                                 const GValue *value,
                                 GParamSpec   *pspec)
{
  ScNavigationPage *self = SC_NAVIGATION_PAGE (object);
  ScNavigationPagePrivate *priv = sc_navigation_page_get_instance_private (self);

  switch (prop_id)
    {
    case PROP_CONTROL_ID_OFFSET:
      priv->control_id_offset = g_value_get_uint (value);
    break;
    case PROP_CONTROL_CC_OFFSET:
      priv->control_cc_offset = g_value_get_uint (value);
    break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}


static void
sc_navigation_page_class_init (ScNavigationPageClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->get_property = sc_navigation_page_get_property;
  object_class->set_property = sc_navigation_page_set_property;

  value_props[PROP_CONTROL_ID_OFFSET] = g_param_spec_uint ("control-id-offset", NULL, NULL,
                                                           0, G_MAXUINT32, 0,
                                                           G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY);

  value_props[PROP_CONTROL_CC_OFFSET] = g_param_spec_uint ("control-cc-offset", NULL, NULL,
                                                           0, G_MAXUINT32, 0,
                                                           G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY);

  g_object_class_install_properties (object_class, LAST_PROP, value_props);
}

static void
sc_navigation_page_init (ScNavigationPage *self)
{
}
