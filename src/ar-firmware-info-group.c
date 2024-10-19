#include "ar-firmware-info-group.h"

#include "ar-book.h"
#include "sc-control.h"
#include "sc-navigation-page.h"

struct _ArFirmwareInfoGroup
{
  AdwPreferencesGroup parent_instance;
  AdwActionRow *firmware_version;
  uint8_t data[11];
};

static void ar_firmware_info_group_interface_init (ScControlInterface *iface);

G_DEFINE_FINAL_TYPE_WITH_CODE (ArFirmwareInfoGroup, ar_firmware_info_group, ADW_TYPE_PREFERENCES_GROUP,
                               G_IMPLEMENT_INTERFACE (SC_TYPE_CONTROL, ar_firmware_info_group_interface_init))

static void
ar_firmware_info_group_class_init (ArFirmwareInfoGroupClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/ar-firmware-info-group.ui");

  gtk_widget_class_bind_template_child (widget_class, ArFirmwareInfoGroup, firmware_version);
}

static int
ar_firmware_info_group_register (ArFirmwareInfoGroup *self)
{
  ScNavigationPage *nav_page = SC_NAVIGATION_PAGE (gtk_widget_get_ancestor (GTK_WIDGET (self), SC_TYPE_NAVIGATION_PAGE));
  sc_navigation_page_register_control (nav_page, SC_CONTROL (self));
  return false;
}

static void
ar_firmware_info_group_init (ArFirmwareInfoGroup *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));

  g_idle_add (G_SOURCE_FUNC (ar_firmware_info_group_register), self);
}

static void
ar_firmware_info_group_update_gui (ScControl *control)
{
  ArFirmwareInfoGroup *self = AR_FIRMWARE_INFO_GROUP (control);

  char version[12];
  uint8_t *d = self->data;

  sprintf(version, "%d.%d.%d", d[10], d[9], d[8]);

  adw_action_row_set_subtitle (self->firmware_version, version);
}

static int
ar_firmware_info_group_read_value (ScControl *control)
{
  ArFirmwareInfoGroup *self = AR_FIRMWARE_INFO_GROUP (control);
  ArBook *book = AR_BOOK (gtk_widget_get_ancestor (GTK_WIDGET (self), AR_TYPE_BOOK));
  return ar_book_device_inquiry (book, self->data);
}

static void
ar_firmware_info_group_interface_init (ScControlInterface *iface)
{
  iface->update_gui = ar_firmware_info_group_update_gui;
  iface->read_value = ar_firmware_info_group_read_value;
}
