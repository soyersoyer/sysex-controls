#pragma once

#include <glib-object.h>

G_BEGIN_DECLS

#define SC_TYPE_CONTROL sc_control_get_type ()

G_DECLARE_INTERFACE (ScControl, sc_control, SC, CONTROL, GObject)

struct _ScControlInterface
{
  GTypeInterface parent_iface;

  int (*read_value) (ScControl *self);
  void (*update_gui) (ScControl *self);
};

int sc_control_read_value (ScControl *self);
void sc_control_update_gui (ScControl  *self);

G_END_DECLS
