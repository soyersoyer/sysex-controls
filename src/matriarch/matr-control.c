#include "matr-control.h"

#include <sc-window.h>

#include "matr-book.h"
#include "sc-control-value.h"
#include "sc-navigation-page.h"
#include "../sc-control.h"

enum {
  PROP_0,
  PROP_ID,
  LAST_PROP,
};

struct _MatrControl {
  AdwBin parent_instance;
  uint8_t id;
  GtkWidget *widget;
  uint16_t value;
};

static GParamSpec *value_props[LAST_PROP];

static void matr_control_interface_init(ScControlInterface *iface);

G_DEFINE_FINAL_TYPE_WITH_CODE(MatrControl, matr_control, ADW_TYPE_BIN,
                              G_IMPLEMENT_INTERFACE (SC_TYPE_CONTROL, matr_control_interface_init))


uint8_t
matr_control_get_id(MatrControl *self) {
  g_return_val_if_fail(MATR_IS_CONTROL (self), 0);
  return self->id;
}


static void
matr_control_get_property(GObject *object,
                          guint prop_id,
                          GValue *value,
                          GParamSpec *pspec) {
  MatrControl *self = MATR_CONTROL(object);

  switch (prop_id) {
    case PROP_ID:
      g_value_set_uint(value, matr_control_get_id(self));
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, prop_id, pspec);
  }
}


static void
matr_control_set_property(GObject *object,
                          guint prop_id,
                          const GValue *value,
                          GParamSpec *pspec) {
  MatrControl *self = MATR_CONTROL(object);

  switch (prop_id) {
    case PROP_ID:
      self->id = g_value_get_uint(value);
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, prop_id, pspec);
  }
}


static void
matr_control_class_init(MatrControlClass *klass) {
  GObjectClass *object_class = G_OBJECT_CLASS(klass);

  object_class->get_property = matr_control_get_property;
  object_class->set_property = matr_control_set_property;

  value_props[PROP_ID] = g_param_spec_uint("id", NULL, NULL,
                                           0, G_MAXUINT8, 0,
                                           G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY);


  g_object_class_install_properties(object_class, LAST_PROP, value_props);
}


static int
matr_control_read_value(ScControl *control) {
  MatrControl *self = MATR_CONTROL(control);
  MatrBook *book = MATR_BOOK(gtk_widget_get_ancestor(GTK_WIDGET(self->widget), MATR_TYPE_BOOK));
  uint16_t value;

  const int ret = matr_book_read_control(book, self->id, &value);

  self->value = value;

  return ret;
}

static void
matr_control_update_gui(ScControl *control) {
  MatrControl *self = MATR_CONTROL(control);

  if (ADW_IS_COMBO_ROW(self->widget)) {
    guint pos = GTK_INVALID_LIST_POSITION;
    AdwComboRow *combo_row = ADW_COMBO_ROW(self->widget);
    GListModel *list = adw_combo_row_get_model(combo_row);
    for (int i = 0; i < g_list_model_get_n_items(list); ++i) {
      ScControlValue *kv = SC_CONTROL_VALUE(g_list_model_get_item(list, i));
      if (sc_control_value_get_value(kv) == self->value) {
        pos = i;
        break;
      }
    }

    if (pos != GTK_INVALID_LIST_POSITION)
      adw_combo_row_set_selected(combo_row, pos);
    else
      g_warning("Set combo row id 0x%08x to invalid pos 0x%02x (value: 0x%02x)", self->id, pos, self->value);

    g_debug("Set combo row id 0x%08x to pos 0x%02x (value: 0x%02x)", self->id, pos, self->value);
  }
}


static void
matr_control_interface_init(ScControlInterface *iface) {
  iface->update_gui = matr_control_update_gui;
  iface->read_value = matr_control_read_value;
}


static void
combo_row_change_cb(GObject *widget, GParamSpec *pspec, MatrControl *self) {
  ScWindow *window = SC_WINDOW(gtk_widget_get_root(GTK_WIDGET(self->widget)));
  MatrBook *book = MATR_BOOK(gtk_widget_get_ancestor(GTK_WIDGET(self->widget), MATR_TYPE_BOOK));
  ScControlValue *item = SC_CONTROL_VALUE(adw_combo_row_get_selected_item(ADW_COMBO_ROW(widget)));
  uint16_t val = sc_control_value_get_value(item);

  if (self->value == val)
    return;

  g_debug("Matriarch parameter change 0x%02x: 0x%04x -> 0x%04x %s", self->id, self->value, val,
          sc_control_value_get_name (item));
  if (matr_book_write_control(book, self->id, val) < 0) {
    sc_io_problem(window, "Matriarch parameter change");
    return;
  }

  self->value = val;
}

static int
matr_control_register(MatrControl *self) {
  GtkWidget *widget = gtk_widget_get_ancestor(GTK_WIDGET(self), ADW_TYPE_COMBO_ROW);
  ScNavigationPage *nav_page_widget = SC_NAVIGATION_PAGE(
    gtk_widget_get_ancestor(GTK_WIDGET(&self->parent_instance), SC_TYPE_NAVIGATION_PAGE));

  g_signal_connect(G_OBJECT (widget), "notify::selected-item", G_CALLBACK (combo_row_change_cb), self);

  sc_navigation_page_register_control(nav_page_widget, SC_CONTROL(self));
  self->widget = widget;

  return false;
}

static void
matr_control_init(MatrControl *self) {
  gtk_widget_set_visible(GTK_WIDGET(&self->parent_instance), false);
  g_idle_add(G_SOURCE_FUNC(matr_control_register), self);
}
