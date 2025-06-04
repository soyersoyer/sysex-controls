#pragma once

#include <glib-object.h>
#include <stdint.h>

G_BEGIN_DECLS

#define MM_TYPE_PAGE mm_page_get_type ()

G_DECLARE_INTERFACE (MmPage, mm_page, MM, PAGE, GObject)

struct _MmPageInterface
{
  GTypeInterface parent_iface;

  int (*read_control) (MmPage *self, uint32_t control_id, uint8_t *value, uint8_t size);
  int (*write_control) (MmPage *self, uint32_t control_id, uint8_t *value, uint8_t size);
};

int mm_page_read_control (MmPage *self, uint32_t control_id, uint8_t *value, uint8_t size);
int mm_page_write_control (MmPage *self, uint32_t control_id, uint8_t *value, uint8_t size);

G_END_DECLS
