#include "korg-firmware-info-group.h"

#include "korg-book.h"
#include "sc-control.h"
#include "sc-navigation-page.h"

#include "ar-firmware-info-group.h"

struct _KorgFirmwareInfoGroup
{
  AdwPreferencesGroup parent_instance;
  AdwActionRow *firmware_version;
  uint8_t data[9];
};

static void korg_firmware_info_group_interface_init (ScControlInterface *iface);

G_DEFINE_FINAL_TYPE_WITH_CODE (KorgFirmwareInfoGroup, korg_firmware_info_group, ADW_TYPE_PREFERENCES_GROUP,
                               G_IMPLEMENT_INTERFACE (SC_TYPE_CONTROL, korg_firmware_info_group_interface_init))

static void
korg_firmware_info_group_class_init (KorgFirmwareInfoGroupClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/korg-firmware-info-group.ui");

  gtk_widget_class_bind_template_child (widget_class, KorgFirmwareInfoGroup, firmware_version);
}

static int
korg_firmware_info_group_register (KorgFirmwareInfoGroup *self)
{
  ScNavigationPage *nav_page = SC_NAVIGATION_PAGE (gtk_widget_get_ancestor (GTK_WIDGET (self), SC_TYPE_NAVIGATION_PAGE));
  sc_navigation_page_register_control (nav_page, SC_CONTROL (self));
  return false;
}

static void
korg_firmware_info_group_init (KorgFirmwareInfoGroup *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));

  g_idle_add (G_SOURCE_FUNC (korg_firmware_info_group_register), self);
}

static void
korg_firmware_info_group_update_gui (ScControl *control)
{
  KorgFirmwareInfoGroup *self = KORG_FIRMWARE_INFO_GROUP (control);

  char version[12];
  uint8_t *d = self->data;

  sprintf(version, "%d.%d", (d[8]<<7) + d[7], (d[6]<<7) + d[5]);

  adw_action_row_set_subtitle (self->firmware_version, version);
}

static int
korg_firmware_info_group_read_value (ScControl *control)
{
  KorgFirmwareInfoGroup *self = KORG_FIRMWARE_INFO_GROUP (control);
  KorgBook *book = KORG_BOOK (gtk_widget_get_ancestor (GTK_WIDGET (self), KORG_TYPE_BOOK));
  return korg_book_device_inquiry (book, self->data);
}

static void
korg_firmware_info_group_interface_init (ScControlInterface *iface)
{
  iface->update_gui = korg_firmware_info_group_update_gui;
  iface->read_value = korg_firmware_info_group_read_value;
}
