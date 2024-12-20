#include "ak-control.h"

#include "ak-program-page.h"
#include "sc-control.h"
#include "sc-control-value.h"
#include "sc-navigation-page.h"
#include "sc-preferences-group.h"
#include "sc-preferences-page.h"
#include "sc-window.h"

enum {
  PROP_0,
  PROP_ID,
  PROP_VALUE_OFFSET,
  PROP_SIZE,
  LAST_PROP,
};

static GParamSpec *value_props[LAST_PROP];

struct _AkControl
{
  AdwBin parent_instance;
  uint32_t id;
  uint32_t real_id;
  uint8_t size;
  uint8_t value[16];
  int8_t value_offset;
  GtkWidget *widget;
};

static void ak_control_interface_init (ScControlInterface *iface);

G_DEFINE_FINAL_TYPE_WITH_CODE (AkControl, ak_control, ADW_TYPE_BIN,
                               G_IMPLEMENT_INTERFACE (SC_TYPE_CONTROL, ak_control_interface_init))

uint32_t
ak_control_get_id (AkControl *self)
{
  g_return_val_if_fail (AK_IS_CONTROL (self), 0);
  return self->id;
}

int8_t
ak_control_get_value_offset (AkControl *self)
{
  g_return_val_if_fail (AK_IS_CONTROL (self), 0);
  return self->value_offset;
}

uint8_t
ak_control_get_size (AkControl *self)
{
  g_return_val_if_fail (AK_IS_CONTROL (self), 0);
  return self->size;
}

static void
ak_control_get_property (GObject    *object,
                         guint       prop_id,
                         GValue     *value,
                         GParamSpec *pspec)
{
  AkControl *self = AK_CONTROL (object);

  switch (prop_id)
    {
    case PROP_ID:
      g_value_set_uint (value, ak_control_get_id (self));
    break;
    case PROP_VALUE_OFFSET:
      g_value_set_int (value, ak_control_get_value_offset (self));
    break;
    case PROP_SIZE:
      g_value_set_uint (value, ak_control_get_size (self));
    break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}

static void
ak_control_set_property (GObject      *object,
                         guint         prop_id,
                         const GValue *value,
                         GParamSpec   *pspec)
{
  AkControl *self = AK_CONTROL (object);

  switch (prop_id)
    {
    case PROP_ID:
      self->id = g_value_get_uint (value);
    break;
    case PROP_VALUE_OFFSET:
      self->value_offset = g_value_get_int (value);
    break;
    case PROP_SIZE:
      self->size = g_value_get_uint (value);
    break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}


static void
ak_control_class_init (AkControlClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->get_property = ak_control_get_property;
  object_class->set_property = ak_control_set_property;

  value_props[PROP_ID] = g_param_spec_uint ("id", NULL, NULL,
                                            0, G_MAXUINT32, 0,
                                            G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY);

  value_props[PROP_VALUE_OFFSET] = g_param_spec_int ("value-offset", NULL, NULL,
                                                     G_MININT8, G_MAXINT8, 0,
                                                     G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY);

  value_props[PROP_SIZE] = g_param_spec_uint ("size", NULL, NULL,
                                                     0, 16, 1,
                                                     G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY);

  g_object_class_install_properties (object_class, LAST_PROP, value_props);
}

static AkProgramPage *
get_program_page (AkControl *self)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *page = ADW_NAVIGATION_PAGE (gtk_widget_get_ancestor (GTK_WIDGET (&self->parent_instance), AK_TYPE_PROGRAM_PAGE));
  if (!AK_IS_PROGRAM_PAGE (page))
    page = adw_navigation_view_get_visible_page (view);
  if (!AK_IS_PROGRAM_PAGE (page))
    page = adw_navigation_view_get_previous_page (view, page);
  if (!AK_IS_PROGRAM_PAGE (page))
    page = adw_navigation_view_get_previous_page (view, page);
  return AK_PROGRAM_PAGE (page);
}

static void
combo_row_change_cb (GObject * widget, GParamSpec *pspec, AkControl *self)
{
  ScWindow *window = SC_WINDOW (gtk_widget_get_root (GTK_WIDGET (self->widget)));
  AkProgramPage *ppage = get_program_page(self);
  ScControlValue *item = SC_CONTROL_VALUE (adw_combo_row_get_selected_item (ADW_COMBO_ROW (widget)));
  uint8_t val = sc_control_value_get_value (item);

  if (self->value[0] == val)
    return;

  g_debug ("combo control change 0x%08x: 0x%02x -> 0x%02x %s", self->real_id, self->value[0], val, sc_control_value_get_name (item));
  if (ak_program_page_write_control (ppage, self->real_id, &val, 1) < 0)
  {
    sc_io_problem (window, "Control change failed");
    return;
  }

  self->value[0] = val;
}

static void
switch_row_change_cb (GObject * widget, GParamSpec *pspec, AkControl *self)
{
  ScWindow *window = SC_WINDOW (gtk_widget_get_root (GTK_WIDGET (self->widget)));
  AkProgramPage *ppage = get_program_page(self);
  AdwSwitchRow *w = ADW_SWITCH_ROW (widget);
  uint8_t val = adw_switch_row_get_active (w);

  if (self->value[0] == val)
    return;

  g_debug ("switch control change 0x%08x: 0x%02x -> 0x%02x", self->real_id, self->value[0], val);
  if (ak_program_page_write_control (ppage, self->real_id, &val, 1) < 0)
  {
    sc_io_problem (window, "Control change failed");
    return;
  }

  self->value[0] = val;
}

static uint16_t
get_dvalue (uint8_t *value, uint8_t size)
{
  if (size == 2)
    return (((uint16_t)value[0] & 0x7f) << 7) | ((uint16_t)value[1] & 0x7f);
  return value[0];
}

static void
spin_row_change_cb (GObject * widget, GParamSpec *pspec, AkControl *self)
{
  ScWindow *window = SC_WINDOW (gtk_widget_get_root (GTK_WIDGET (self->widget)));
  AkProgramPage *ppage = get_program_page(self);
  AdwSpinRow *w = ADW_SPIN_ROW (self->widget);
  uint16_t val = (uint8_t)adw_spin_row_get_value (w) - self->value_offset;
  uint16_t dvalue = get_dvalue (self->value, self->size);

  if (dvalue == val)
    return;

  g_debug("spin control change 0x%08x: 0x%02x -> 0x%02x", self->real_id, dvalue, val);

  self->value[0] = val & 0x7f;

  if (self->size == 2) {
    self->value[0] = (val >> 7) & 0x7f;
    self->value[1] = val & 0x7f;
  }

  if (ak_program_page_write_control (ppage, self->real_id, self->value, self->size) < 0)
  {
    sc_io_problem (window, "Control change failed");

    /*
     * When setting page replaced by search page this spins forever
     * toggle sensitivity to stop, possibly a GTK bug?
     *
     * Now it emit this warning:
     * GtkText - did not receive a focus-out event.
     * If you handle this event, you must return
     * GDK_EVENT_PROPAGATE so the default handler gets the event as well
     */
    gtk_widget_set_sensitive (GTK_WIDGET (w), false);
    gtk_widget_set_sensitive (GTK_WIDGET (w), true);

    return;
  }
}

static void
entry_row_change_cb (AdwEntryRow* widget, AkControl *self)
{
  ScWindow *window = SC_WINDOW (gtk_widget_get_root (GTK_WIDGET (self->widget)));
  AkProgramPage *ppage = get_program_page(self);
  AdwEntryRow *w = ADW_ENTRY_ROW (self->widget);
  GtkEditable *e = GTK_EDITABLE (w);
  const char* new_text = gtk_editable_get_text (e);

  if (strncmp((char*)self->value, new_text, 16) == 0)
    return;

  g_debug("entry control change 0x%08x: %s -> %s", self->real_id, self->value, new_text);

  strncpy((char*)self->value, new_text, 16);
  self->value[15] = 0;

  if (ak_program_page_write_control (ppage, self->real_id, self->value, self->size) < 0)
  {
    sc_io_problem (window, "Control change failed");
    return;
  }
}

static int
ak_control_register (AkControl *self)
{
  ScPreferencesGroup *group_widget;
  ScPreferencesPage *page_widget;
  ScNavigationPage *nav_page_widget;
  GtkWidget *widget;
  self->real_id = self->id;

  widget = gtk_widget_get_ancestor (GTK_WIDGET (&self->parent_instance), ADW_TYPE_COMBO_ROW);

  if (!widget)
    widget = gtk_widget_get_ancestor (GTK_WIDGET (&self->parent_instance), GTK_TYPE_DROP_DOWN);

  if (!widget)
    widget = gtk_widget_get_ancestor (GTK_WIDGET (&self->parent_instance), ADW_TYPE_SPIN_ROW);

  if (!widget)
    widget = gtk_widget_get_ancestor (GTK_WIDGET (&self->parent_instance), ADW_TYPE_SWITCH_ROW);

  if (!widget)
    widget = gtk_widget_get_ancestor (GTK_WIDGET (&self->parent_instance), ADW_TYPE_ENTRY_ROW);

  nav_page_widget = SC_NAVIGATION_PAGE (gtk_widget_get_ancestor (GTK_WIDGET (&self->parent_instance), SC_TYPE_NAVIGATION_PAGE));
  if (nav_page_widget) {
    self->real_id += sc_navigation_page_get_control_id_offset (nav_page_widget);
  }

  page_widget = SC_PREFERENCES_PAGE (gtk_widget_get_ancestor (GTK_WIDGET (&self->parent_instance), SC_TYPE_PREFERENCES_PAGE));
  if (page_widget) {
    self->real_id += sc_preferences_page_get_control_id_offset (page_widget);
  }

  group_widget = SC_PREFERENCES_GROUP (gtk_widget_get_ancestor (GTK_WIDGET (&self->parent_instance), SC_TYPE_PREFERENCES_GROUP));
  if (group_widget) {
    self->real_id += sc_preferences_group_get_control_id_offset (group_widget);
  }

  self->value[0] = 0;
  self->widget = widget;
  sc_navigation_page_register_control (nav_page_widget, SC_CONTROL (self));

  if (ADW_IS_COMBO_ROW (widget))
    g_signal_connect (G_OBJECT (widget), "notify::selected-item", G_CALLBACK (combo_row_change_cb), self);
  else if (ADW_IS_SWITCH_ROW (widget))
    g_signal_connect (G_OBJECT (widget), "notify::active", G_CALLBACK (switch_row_change_cb), self);
  else if (ADW_IS_SPIN_ROW (widget))
    g_signal_connect (G_OBJECT (widget), "notify::value", G_CALLBACK (spin_row_change_cb), self);
  else if (ADW_IS_ENTRY_ROW (widget))
    g_signal_connect (G_OBJECT (widget), "apply", G_CALLBACK (entry_row_change_cb), self);
  else
    g_error("Unsupported control type: %s id: 0x%08x",
            gtk_widget_get_name (GTK_WIDGET (widget)),
            self->real_id);

  return false;
}

static void
ak_control_update_gui (ScControl *control)
{
  AkControl *self = AK_CONTROL (control);

  if (ADW_IS_COMBO_ROW (self->widget))
  {
    guint pos = GTK_INVALID_LIST_POSITION;
    AdwComboRow* combo_row = ADW_COMBO_ROW (self->widget);
    GListModel* list = adw_combo_row_get_model (combo_row);
    for(int i = 0; i < g_list_model_get_n_items (list); ++i)
    {
      ScControlValue *kv = SC_CONTROL_VALUE (g_list_model_get_item (list, i));
      if (sc_control_value_get_value (kv) == self->value[0])
      {
        pos = i;
        break;
      }
    }

    if (pos != GTK_INVALID_LIST_POSITION)
      adw_combo_row_set_selected (combo_row, pos);
    else
      g_warning("Set combo row id 0x%02x to invalid pos 0x%02x", self->real_id, pos);

    g_debug("Set combo row id 0x%02x to pos 0x%02x", self->real_id, pos);
  }
  else if (ADW_IS_SWITCH_ROW (self->widget))
  {
    AdwSwitchRow *switch_row = ADW_SWITCH_ROW (self->widget);
    adw_switch_row_set_active (switch_row, self->value[0]);
    g_debug ("Set switch row with id 0x%02x to 0x%02x", self->real_id, self->value[0]);
  }
  else if (ADW_IS_SPIN_ROW (self->widget))
  {
    AdwSpinRow *spin_row = ADW_SPIN_ROW (self->widget);
    uint16_t dvalue = get_dvalue(self->value, self->size);
    adw_spin_row_set_value (spin_row, dvalue + self->value_offset);
    g_debug ("Set spin row with id 0x%02x to 0x%02x (%+02d)", self->real_id, dvalue, self->value_offset);
  }
  else if (ADW_IS_ENTRY_ROW (self->widget))
  {
    GtkEditable *editable = GTK_EDITABLE (self->widget);
    gtk_editable_set_text (editable, (char*)self->value);
    g_debug ("Set entry row with id 0x%02x to %s", self->real_id, self->value);
  }
  else {
    g_error ("Unsupported control type: %s id: 0x%02x",
              gtk_widget_get_name (GTK_WIDGET (self->widget)),
              self->real_id);
    }
}

static int
ak_control_read_value (ScControl *control)
{
  AkControl *self = AK_CONTROL (control);
  AkProgramPage *ppage = get_program_page (self);

  return ak_program_page_read_control (ppage, self->real_id, self->value, self->size);
}

static void
ak_control_interface_init (ScControlInterface *iface)
{
  iface->update_gui = ak_control_update_gui;
  iface->read_value = ak_control_read_value;
}

static void
ak_control_init (AkControl *self)
{
  gtk_widget_set_visible (GTK_WIDGET (&self->parent_instance), false);
  g_idle_add (G_SOURCE_FUNC (ak_control_register), self);
}
