#include "korg-scene-page.h"

#include "mm-page.h"
#include "korg-book.h"

enum {
  PROP_0,
  PROP_SCENE_ID,
  LAST_PROP,
};

static GParamSpec *value_props[LAST_PROP];

typedef struct
{
  uint8_t scene_id;
  uint8_t data[512];
  uint16_t size;
} KorgScenePagePrivate;

static void sc_control_interface_init (ScControlInterface *iface);
static void mm_page_interface_init (MmPageInterface *iface);

G_DEFINE_TYPE_WITH_CODE (KorgScenePage, korg_scene_page, SC_TYPE_NAVIGATION_PAGE,
                         G_ADD_PRIVATE (KorgScenePage)
                         G_IMPLEMENT_INTERFACE (SC_TYPE_CONTROL, sc_control_interface_init)
                         G_IMPLEMENT_INTERFACE (MM_TYPE_PAGE, mm_page_interface_init))

uint8_t
korg_scene_page_get_scene_id (KorgScenePage *self)
{
  KorgScenePagePrivate *priv = korg_scene_page_get_instance_private (self);
  return priv->scene_id;
}

static void
korg_scene_page_get_property (GObject    *object,
                              guint       prop_id,
                              GValue     *value,
                              GParamSpec *pspec)
{
  KorgScenePage *self = KORG_SCENE_PAGE (object);

  switch (prop_id)
    {
    case PROP_SCENE_ID:
      g_value_set_uint (value, korg_scene_page_get_scene_id (self));
    break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}


static void
korg_scene_page_set_property (GObject      *object,
                              guint         prop_id,
                              const GValue *value,
                              GParamSpec   *pspec)
{
  KorgScenePage *self = KORG_SCENE_PAGE (object);
  KorgScenePagePrivate *priv = korg_scene_page_get_instance_private (self);

  switch (prop_id)
    {
    case PROP_SCENE_ID:
      priv->scene_id = g_value_get_uint (value);
    break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}

static void
korg_scene_page_class_init (KorgScenePageClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->get_property = korg_scene_page_get_property;
  object_class->set_property = korg_scene_page_set_property;

  value_props[PROP_SCENE_ID] = g_param_spec_uint ("scene-id", NULL, NULL,
                                                 0, G_MAXUINT8, 0,
                                                 G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY);

  g_object_class_install_properties (object_class, LAST_PROP, value_props);
}

static char *
values_to_buf (char buf[80], uint8_t *value, uint8_t size)
{
  for (int i = 0; i < size; ++i)
    snprintf (buf + i * 3, 80 - i * 3, "%02x ", value[i]);
  return buf;
}

static int
korg_scene_page_read_control (MmPage *self, uint32_t control_id, uint8_t *value, uint8_t size)
{
  KorgScenePagePrivate *priv;
  char buf[80];
  g_return_val_if_fail (KORG_IS_SCENE_PAGE (self), -EINVAL);

  priv = korg_scene_page_get_instance_private (KORG_SCENE_PAGE (self));

  if (control_id >= priv->size || control_id + size > priv->size) {
    g_error ("%s (%02x::%02x) %02x+%02x exceeds internal buffer size %02x", __func__, priv->scene_id, control_id, control_id, size, priv->size);
    return -EINVAL;
  }

  memcpy (value, &priv->data[control_id], size);

  g_debug("%s (%02x::%02x) -> %s", __func__, priv->scene_id, control_id, values_to_buf (buf, value, size));

  return 0;
}

static int
korg_scene_page_write_control (MmPage *self, uint32_t control_id, uint8_t *value, uint8_t size)
{
  KorgBook *book;
  KorgScenePagePrivate *priv;
  char buf[80];

  g_return_val_if_fail (KORG_IS_SCENE_PAGE (self), -EINVAL);

  book = KORG_BOOK (gtk_widget_get_ancestor (GTK_WIDGET (self), KORG_TYPE_BOOK));
  priv = korg_scene_page_get_instance_private (KORG_SCENE_PAGE (self));

  if (control_id >= priv->size || control_id + size > priv->size)
    return -EINVAL;

  memcpy (&priv->data[control_id], value, size);

  g_debug("%s (%02x::%02x) <- %s", __func__, priv->scene_id, control_id, values_to_buf (buf, value, size));

  return korg_book_write_scene (book, priv->scene_id, priv->data, priv->size);
}

static void
korg_scene_page_update_gui (ScControl *control)
{
}

static int
korg_scene_page_read_scene (ScControl *control)
{
  KorgScenePage *self = KORG_SCENE_PAGE (control);
  KorgScenePagePrivate *priv = korg_scene_page_get_instance_private (self);
  KorgBook *book = KORG_BOOK (gtk_widget_get_ancestor (GTK_WIDGET (self), KORG_TYPE_BOOK));
  int err;
  g_debug("%s (%02x)", __func__, priv->scene_id);
  err = korg_book_read_scene (book, priv->scene_id, priv->data, &priv->size);
  if (err < 0)
    g_debug("korg_book_read_scene failed %d", err);
  return err;
}

static void
sc_control_interface_init (ScControlInterface *iface)
{
  iface->update_gui = korg_scene_page_update_gui;
  iface->read_value = korg_scene_page_read_scene;
}

static void
mm_page_interface_init (MmPageInterface *iface)
{
  iface->read_control = korg_scene_page_read_control;
  iface->write_control = korg_scene_page_write_control;
}

static int
korg_scene_page_add_self (KorgScenePage *self)
{
  sc_navigation_page_register_control (SC_NAVIGATION_PAGE (self), SC_CONTROL (self));
  return 0;
}

static void
korg_scene_page_init (KorgScenePage *self)
{
  KorgScenePagePrivate *priv = korg_scene_page_get_instance_private (self);
  priv->size = 512;

  g_idle_add (G_SOURCE_FUNC (korg_scene_page_add_self), self);
}
