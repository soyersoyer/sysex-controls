#include "sc-midi-connect.h"

#include "sc-arturia-book.h"
#include "sc-preferences-page.h"
#include "sc-preferences-group.h"

enum {
  PROP_0,
  PROP_CONTROL_ID,
  LAST_PROP,
};

struct _ScMidiConnect
{
  AdwBin parent_instance;
  uint16_t control_id;
};

static GParamSpec *value_props[LAST_PROP];

G_DEFINE_FINAL_TYPE (ScMidiConnect, sc_midi_connect, ADW_TYPE_BIN)

uint16_t
sc_midi_connect_get_control_id (ScMidiConnect *self)
{
  g_return_val_if_fail (SC_IS_MIDI_CONNECT (self), 0);
  return self->control_id;
}

static void
sc_midi_connect_get_property (GObject    *object,
                              guint       prop_id,
                              GValue     *value,
                              GParamSpec *pspec)
{
  ScMidiConnect *self = SC_MIDI_CONNECT (object);

  switch (prop_id)
    {
    case PROP_CONTROL_ID:
      g_value_set_uint (value, sc_midi_connect_get_control_id (self));
    break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}


static void
sc_midi_connect_set_property (GObject      *object,
                              guint         prop_id,
                              const GValue *value,
                              GParamSpec   *pspec)
{
  ScMidiConnect *self = SC_MIDI_CONNECT (object);

  switch (prop_id)
    {
    case PROP_CONTROL_ID:
      self->control_id = g_value_get_uint (value);
    break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}

static void
sc_midi_connect_class_init (ScMidiConnectClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->get_property = sc_midi_connect_get_property;
  object_class->set_property = sc_midi_connect_set_property;

  value_props[PROP_CONTROL_ID] = g_param_spec_uint ("control-id", NULL, NULL,
                                                    0, G_MAXUINT16, 0,
                                                    G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY);

  g_object_class_install_properties (object_class, LAST_PROP, value_props);
}

static int
sc_midi_connect_register (void *widget)
{
  ScMidiConnect *self = SC_MIDI_CONNECT (widget);
  GtkWidget *adw_widget, *page_widget, *group_widget;
  uint16_t control_id = self->control_id;

  adw_widget = gtk_widget_get_ancestor (GTK_WIDGET (&self->parent_instance), ADW_TYPE_COMBO_ROW);

  if (!adw_widget)
    adw_widget = gtk_widget_get_ancestor (GTK_WIDGET (&self->parent_instance), ADW_TYPE_SPIN_ROW);

  if (!adw_widget)
    adw_widget = gtk_widget_get_ancestor (GTK_WIDGET (&self->parent_instance), ADW_TYPE_SWITCH_ROW);

  page_widget = gtk_widget_get_ancestor (GTK_WIDGET (&self->parent_instance), SC_TYPE_PREFERENCES_PAGE);
  if (page_widget)
    control_id += sc_preferences_page_get_control_id_offset (SC_PREFERENCES_PAGE (page_widget));


  group_widget = gtk_widget_get_ancestor (GTK_WIDGET (&self->parent_instance), SC_TYPE_PREFERENCES_GROUP);
  if (group_widget)
    control_id += sc_preferences_group_get_control_id_offset (SC_PREFERENCES_GROUP (group_widget));

  sc_arturia_book_register_control (SC_ARTURIA_BOOK (gtk_widget_get_ancestor (GTK_WIDGET (adw_widget), SC_TYPE_ARTURIA_BOOK)), control_id, adw_widget);

  return false;
}

static void
sc_midi_connect_register_cb (ScMidiConnect *self)
{
  g_idle_add (sc_midi_connect_register, self);
}

static void
sc_midi_connect_init (ScMidiConnect *self)
{
  gtk_widget_set_visible (GTK_WIDGET (&self->parent_instance), false);
  g_signal_connect (G_OBJECT (self), "notify::control-id", G_CALLBACK (sc_midi_connect_register_cb), NULL);
}

