#include "mm-control.h"

#include "mm-page.h"
#include "sc-control.h"
#include "sc-control-value.h"
#include "sc-navigation-page.h"
#include "sc-preferences-group.h"
#include "sc-preferences-page.h"
#include "sc-window.h"

enum {
  PROP_0,
  PROP_ID,
  PROP_USE_CC_OFFSET,
  PROP_VALUE_OFFSET,
  PROP_SIZE,
  PROP_MASK,
  PROP_MULTIPLY,
  LAST_PROP,
};

static GParamSpec *value_props[LAST_PROP];

struct _MmControl
{
  AdwBin parent_instance;
  uint32_t id;
  gboolean use_cc_offset;
  uint32_t real_id;
  uint8_t size;
  uint8_t mask;
  double multiply;
  uint8_t value[16];
  int8_t value_offset;
  GtkWidget *widget;
};

static void mm_control_interface_init (ScControlInterface *iface);

G_DEFINE_FINAL_TYPE_WITH_CODE (MmControl, mm_control, ADW_TYPE_BIN,
                               G_IMPLEMENT_INTERFACE (SC_TYPE_CONTROL, mm_control_interface_init))

uint32_t
mm_control_get_id (MmControl *self)
{
  g_return_val_if_fail (MM_IS_CONTROL (self), 0);
  return self->id;
}

gboolean
mm_control_get_use_cc_offset (MmControl *self)
{
  g_return_val_if_fail (MM_IS_CONTROL (self), 0);
  return self->use_cc_offset;
}

int8_t
mm_control_get_value_offset (MmControl *self)
{
  g_return_val_if_fail (MM_IS_CONTROL (self), 0);
  return self->value_offset;
}

uint8_t
mm_control_get_size (MmControl *self)
{
  g_return_val_if_fail (MM_IS_CONTROL (self), 0);
  return self->size;
}

uint8_t
mm_control_get_mask (MmControl *self)
{
  g_return_val_if_fail (MM_IS_CONTROL (self), 0);
  return self->mask;
}

double
mm_control_get_multiply (MmControl *self)
{
  g_return_val_if_fail (MM_IS_CONTROL (self), 0);
  return self->multiply;
}

static void
mm_control_get_property (GObject    *object,
                         guint       prop_id,
                         GValue     *value,
                         GParamSpec *pspec)
{
  MmControl *self = MM_CONTROL (object);

  switch (prop_id)
    {
    case PROP_ID:
      g_value_set_uint (value, mm_control_get_id (self));
    break;
    case PROP_USE_CC_OFFSET:
      g_value_set_boolean (value, mm_control_get_use_cc_offset (self));
    break;
    case PROP_VALUE_OFFSET:
      g_value_set_int (value, mm_control_get_value_offset (self));
    break;
    case PROP_SIZE:
      g_value_set_uint (value, mm_control_get_size (self));
    break;
    case PROP_MASK:
      g_value_set_uint (value, mm_control_get_mask (self));
    break;
    case PROP_MULTIPLY:
      g_value_set_double (value, mm_control_get_multiply (self));
    break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}

static void
mm_control_set_property (GObject      *object,
                         guint         prop_id,
                         const GValue *value,
                         GParamSpec   *pspec)
{
  MmControl *self = MM_CONTROL (object);

  switch (prop_id)
    {
    case PROP_ID:
      self->id = g_value_get_uint (value);
    break;
    case PROP_USE_CC_OFFSET:
      self->use_cc_offset = g_value_get_boolean (value);
    break;
    case PROP_VALUE_OFFSET:
      self->value_offset = g_value_get_int (value);
    break;
    case PROP_SIZE:
      self->size = g_value_get_uint (value);
    break;
    case PROP_MASK:
      self->mask = g_value_get_uint (value);
    break;
    case PROP_MULTIPLY:
      self->multiply = g_value_get_double (value);
    break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}


static void
mm_control_class_init (MmControlClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->get_property = mm_control_get_property;
  object_class->set_property = mm_control_set_property;

  value_props[PROP_ID] = g_param_spec_uint ("id", NULL, NULL,
                                            0, G_MAXUINT32, 0,
                                            G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY);

  value_props[PROP_USE_CC_OFFSET] = g_param_spec_boolean ("use-cc-offset", NULL, NULL,
                                                          0,
                                                          G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY);

  value_props[PROP_VALUE_OFFSET] = g_param_spec_int ("value-offset", NULL, NULL,
                                                     G_MININT8, G_MAXINT8, 0,
                                                     G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY);

  value_props[PROP_SIZE] = g_param_spec_uint ("size", NULL, NULL,
                                                     0, 16, 1,
                                                     G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY);

  value_props[PROP_MASK] = g_param_spec_uint ("mask", NULL, NULL,
                                                     0, 0xff, 0xff,
                                                     G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY);

  value_props[PROP_MULTIPLY] = g_param_spec_double ("multiply", NULL, NULL,
                                                    0, G_MAXDOUBLE, 1,
                                                    G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY);

  g_object_class_install_properties (object_class, LAST_PROP, value_props);
}

static MmPage *
get_mm_page (MmControl *self)
{
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (self), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *page = ADW_NAVIGATION_PAGE (gtk_widget_get_ancestor (GTK_WIDGET (&self->parent_instance), MM_TYPE_PAGE));
  if (!MM_IS_PAGE (page))
    page = adw_navigation_view_get_visible_page (view);
  if (!MM_IS_PAGE (page))
    page = adw_navigation_view_get_previous_page (view, page);
  if (!MM_IS_PAGE (page))
    page = adw_navigation_view_get_previous_page (view, page);
  if (!MM_IS_PAGE (page))
    page = adw_navigation_view_get_previous_page (view, page);
  return MM_PAGE (page);
}

static void
combo_row_change_cb (GObject * widget, GParamSpec *pspec, MmControl *self)
{
  ScWindow *window = SC_WINDOW (gtk_widget_get_root (GTK_WIDGET (self->widget)));
  MmPage *page = get_mm_page (self);
  ScControlValue *item = SC_CONTROL_VALUE (adw_combo_row_get_selected_item (ADW_COMBO_ROW (widget)));
  uint8_t val = sc_control_value_get_value (item);

  if (self->value[0] == val)
    return;

  g_debug ("combo control change 0x%08x: 0x%02x -> 0x%02x %s", self->real_id, self->value[0], val, sc_control_value_get_name (item));
  if (mm_page_write_control (page, self->real_id, &val, 1, self->mask) < 0)
  {
    sc_io_problem (window, "Control change failed");
    return;
  }

  self->value[0] = val;
}

static void
switch_row_change_cb (GObject * widget, GParamSpec *pspec, MmControl *self)
{
  ScWindow *window = SC_WINDOW (gtk_widget_get_root (GTK_WIDGET (self->widget)));
  MmPage *page = get_mm_page (self);
  AdwSwitchRow *w = ADW_SWITCH_ROW (widget);
  uint8_t val = adw_switch_row_get_active (w);

  if (self->value[0] == val)
    return;

  g_debug ("switch control change 0x%08x: 0x%02x -> 0x%02x", self->real_id, self->value[0], val);
  if (mm_page_write_control (page, self->real_id, &val, 1, self->mask) < 0)
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
spin_row_change_cb (GObject * widget, GParamSpec *pspec, MmControl *self)
{
  ScWindow *window = SC_WINDOW (gtk_widget_get_root (GTK_WIDGET (self->widget)));
  MmPage *page = get_mm_page (self);
  AdwSpinRow *w = ADW_SPIN_ROW (self->widget);
  uint16_t val = (uint16_t)((adw_spin_row_get_value (w) - self->value_offset) * self->multiply);
  uint16_t dvalue = get_dvalue (self->value, self->size);

  if (dvalue == val)
    return;

  g_debug("spin control change 0x%08x: 0x%02x -> 0x%02x (x%.0f)", self->real_id, dvalue, val, self->multiply);

  self->value[0] = val & 0x7f;

  if (self->size == 2) {
    self->value[0] = (val >> 7) & 0x7f;
    self->value[1] = val & 0x7f;
  }

  if (mm_page_write_control (page, self->real_id, self->value, self->size, self->mask) < 0)
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
entry_row_change_cb (AdwEntryRow* widget, MmControl *self)
{
  ScWindow *window = SC_WINDOW (gtk_widget_get_root (GTK_WIDGET (self->widget)));
  MmPage *page = get_mm_page (self);
  AdwEntryRow *w = ADW_ENTRY_ROW (self->widget);
  GtkEditable *e = GTK_EDITABLE (w);
  const char* new_text = gtk_editable_get_text (e);

  if (strncmp((char*)self->value, new_text, 16) == 0)
    return;

  g_debug("entry control change 0x%08x: %s -> %s", self->real_id, self->value, new_text);

  strncpy((char*)self->value, new_text, 16);
  self->value[15] = 0;

  if (mm_page_write_control (page, self->real_id, self->value, self->size, self->mask) < 0)
  {
    sc_io_problem (window, "Control change failed");
    return;
  }
}

static int
mm_control_register (MmControl *self)
{
  ScPreferencesGroup *group_widget;
  ScPreferencesPage *page_widget;
  ScNavigationPage *nav_page_widget;
  GtkWidget *widget;
  uint32_t offset = 0;

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
    uint32_t cc_offset = sc_navigation_page_get_control_cc_offset (nav_page_widget);
    offset += self->use_cc_offset && cc_offset ? cc_offset : sc_navigation_page_get_control_id_offset (nav_page_widget);
  }

  page_widget = SC_PREFERENCES_PAGE (gtk_widget_get_ancestor (GTK_WIDGET (&self->parent_instance), SC_TYPE_PREFERENCES_PAGE));
  if (page_widget) {
    uint32_t cc_offset = sc_preferences_page_get_control_cc_offset (page_widget);
    offset += self->use_cc_offset && cc_offset ? cc_offset : sc_preferences_page_get_control_id_offset (page_widget);
  }

  group_widget = SC_PREFERENCES_GROUP (gtk_widget_get_ancestor (GTK_WIDGET (&self->parent_instance), SC_TYPE_PREFERENCES_GROUP));
  if (group_widget) {
    uint32_t cc_offset = sc_preferences_group_get_control_cc_offset (group_widget);
    offset += self->use_cc_offset && cc_offset ? cc_offset : sc_preferences_group_get_control_id_offset (group_widget);
  }

  self->real_id = self->id + offset;
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
mm_control_update_gui (ScControl *control)
{
  MmControl *self = MM_CONTROL (control);

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
    adw_spin_row_set_value (spin_row, (dvalue / self->multiply) + self->value_offset);
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
mm_control_read_value (ScControl *control)
{
  MmControl *self = MM_CONTROL (control);
  MmPage *page = get_mm_page (self);

  return mm_page_read_control (page, self->real_id, self->value, self->size, self->mask);
}

static void
mm_control_interface_init (ScControlInterface *iface)
{
  iface->update_gui = mm_control_update_gui;
  iface->read_value = mm_control_read_value;
}

static void
mm_control_init (MmControl *self)
{
  self->mask = 0xff;
  self->multiply = 1.0f;
  gtk_widget_set_visible (GTK_WIDGET (&self->parent_instance), false);
  g_idle_add (G_SOURCE_FUNC (mm_control_register), self);
}
