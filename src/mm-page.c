#include "mm-page.h"

G_DEFINE_INTERFACE (MmPage, mm_page, G_TYPE_OBJECT)

static void
mm_page_default_init (MmPageInterface *iface)
{
}

int
mm_page_read_control (MmPage *self, uint32_t control_id, uint8_t *value, uint8_t size)
{
  MmPageInterface *iface;

  g_return_val_if_fail (MM_IS_PAGE (self), -EINVAL);

  iface = MM_PAGE_GET_IFACE (self);
  g_return_val_if_fail (iface->read_control != NULL, -EINVAL);

  return iface->read_control (self, control_id, value, size);
}

int
mm_page_write_control (MmPage *self, uint32_t control_id, uint8_t *value, uint8_t size)
{
  MmPageInterface *iface;

  g_return_val_if_fail (MM_IS_PAGE (self), -EINVAL);

  iface = MM_PAGE_GET_IFACE (self);
  g_return_val_if_fail (iface->write_control != NULL, -EINVAL);

  return iface->write_control (self, control_id, value, size);
}
