#include "sc-control.h"

G_DEFINE_INTERFACE (ScControl, sc_control, G_TYPE_OBJECT)

static void
sc_control_default_init (ScControlInterface *iface)
{
}

int
sc_control_read_value (ScControl *self)
{
  ScControlInterface *iface;

  g_return_val_if_fail (SC_IS_CONTROL (self), -EINVAL);

  iface = SC_CONTROL_GET_IFACE (self);
  g_return_val_if_fail (iface->read_value != NULL, -EINVAL);

  return iface->read_value (self);
}

void
sc_control_update_gui (ScControl *self)
{
  ScControlInterface *iface;

  g_return_if_fail (SC_IS_CONTROL (self));

  iface = SC_CONTROL_GET_IFACE (self);
  g_return_if_fail (iface->update_gui != NULL);

  iface->update_gui (self);
}
