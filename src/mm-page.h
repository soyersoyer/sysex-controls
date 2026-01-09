#pragma once

#include <glib-object.h>
#include <stdint.h>

G_BEGIN_DECLS

#define MM_TYPE_PAGE mm_page_get_type ()

G_DECLARE_INTERFACE (MmPage, mm_page, MM, PAGE, GObject)

struct _MmPageInterface
{
  GTypeInterface parent_iface;

  int (*read_control) (MmPage *self, uint32_t control_id, uint8_t *value, uint8_t size, uint8_t mask);
  int (*write_control) (MmPage *self, uint32_t control_id, uint8_t *value, uint8_t size, uint8_t mask);
};

int mm_page_read_control (MmPage *self, uint32_t control_id, uint8_t *value, uint8_t size, uint8_t mask);
int mm_page_write_control (MmPage *self, uint32_t control_id, uint8_t *value, uint8_t size, uint8_t mask);

G_END_DECLS
