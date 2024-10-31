#include "ak-program-page.h"

#include "ak-book.h"

enum {
  PROP_0,
  PROP_PROG_ID,
  LAST_PROP,
};

static GParamSpec *value_props[LAST_PROP];

typedef struct
{
  uint8_t prog_id;
  uint8_t data[512];
  uint16_t size;
} AkProgramPagePrivate;

static void ak_program_page_interface_init (ScControlInterface *iface);

G_DEFINE_TYPE_WITH_CODE (AkProgramPage, ak_program_page, SC_TYPE_NAVIGATION_PAGE,
                         G_ADD_PRIVATE (AkProgramPage)
                         G_IMPLEMENT_INTERFACE (SC_TYPE_CONTROL, ak_program_page_interface_init))

uint8_t
ak_program_page_get_prog_id (AkProgramPage *self)
{
  AkProgramPagePrivate *priv = ak_program_page_get_instance_private (self);
  return priv->prog_id;
}

static void
ak_program_page_get_property (GObject    *object,
                              guint       prop_id,
                              GValue     *value,
                              GParamSpec *pspec)
{
  AkProgramPage *self = AK_PROGRAM_PAGE (object);

  switch (prop_id)
    {
    case PROP_PROG_ID:
      g_value_set_uint (value, ak_program_page_get_prog_id (self));
    break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}


static void
ak_program_page_set_property (GObject      *object,
                              guint         prop_id,
                              const GValue *value,
                              GParamSpec   *pspec)
{
  AkProgramPage *self = AK_PROGRAM_PAGE (object);
  AkProgramPagePrivate *priv = ak_program_page_get_instance_private (self);

  switch (prop_id)
    {
    case PROP_PROG_ID:
      priv->prog_id = g_value_get_uint (value);
    break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}

static void
ak_program_page_class_init (AkProgramPageClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->get_property = ak_program_page_get_property;
  object_class->set_property = ak_program_page_set_property;

  value_props[PROP_PROG_ID] = g_param_spec_uint ("prog-id", NULL, NULL,
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

int
ak_program_page_read_control (AkProgramPage *self, uint32_t control_id, uint8_t *value, uint8_t size)
{
  AkProgramPagePrivate *priv;
  char buf[80];
  g_return_val_if_fail (AK_IS_PROGRAM_PAGE (self), -EINVAL);

  priv = ak_program_page_get_instance_private (self);

  if (control_id >= priv->size || control_id + size > priv->size)
    return -EINVAL;

  memcpy (value, &priv->data[control_id], size);

  g_debug("%s (%02d::%02x) -> %s", __func__, priv->prog_id, control_id, values_to_buf (buf, value, size));

  return 0;
}

int
ak_program_page_write_control (AkProgramPage *self, uint32_t control_id, uint8_t *value, uint8_t size)
{
  AkBook *book;
  AkProgramPagePrivate *priv;
  char buf[80];

  g_return_val_if_fail (AK_IS_PROGRAM_PAGE (self), -EINVAL);

  book = AK_BOOK (gtk_widget_get_ancestor (GTK_WIDGET (self), AK_TYPE_BOOK));
  priv = ak_program_page_get_instance_private (self);

  if (control_id >= priv->size || control_id + size > priv->size)
    return -EINVAL;

  memcpy (&priv->data[control_id], value, size);

  g_debug("%s (%02x::%02x) <- %s", __func__, priv->prog_id, control_id, values_to_buf (buf, value, size));

  ak_book_write_program (book, priv->prog_id, priv->data, priv->size);

  return 0;
}

static void
ak_program_page_update_gui (ScControl *control)
{
}

static int
ak_program_page_read_program (ScControl *control)
{
  AkProgramPage *self = AK_PROGRAM_PAGE (control);
  AkProgramPagePrivate *priv = ak_program_page_get_instance_private (self);
  AkBook *book = AK_BOOK (gtk_widget_get_ancestor (GTK_WIDGET (self), AK_TYPE_BOOK));
  int err;
  g_debug("%s (%d)", __func__, priv->prog_id);
  err = ak_book_read_program (book, priv->prog_id, priv->data, &priv->size);
  if (err < 0)
    g_debug("ak_book_read_program failed %d", err);
  return err;
}

static void
ak_program_page_interface_init (ScControlInterface *iface)
{
  iface->update_gui = ak_program_page_update_gui;
  iface->read_value = ak_program_page_read_program;
}

static int
ak_program_page_add_self (AkProgramPage *self)
{
  sc_navigation_page_register_control (SC_NAVIGATION_PAGE (self), SC_CONTROL (self));
  return 0;
}

static void
ak_program_page_init (AkProgramPage *self)
{
  AkProgramPagePrivate *priv = ak_program_page_get_instance_private (self);
  priv->size = 512;

  g_idle_add (G_SOURCE_FUNC (ak_program_page_add_self), self);
}
