#include "ks37-midi-connect.h"

#include "ks37-window.h"
#include "ks37-preferences-page.h"
#include "ks37-preferences-group.h"

enum {
	PROP_0,
	PROP_MIDI_ID,
	LAST_PROP,
};

struct _Ks37MidiConnect
{
	AdwBin parent_instance;
	uint8_t midi_id;
};

static GParamSpec *value_props[LAST_PROP];

G_DEFINE_FINAL_TYPE (Ks37MidiConnect, ks37_midi_connect, ADW_TYPE_BIN)

uint8_t ks37_midi_connect_get_midi_id (Ks37MidiConnect *self)
{
	g_return_val_if_fail (KS37_IS_MIDI_CONNECT (self), 0);
	return self->midi_id;
}

static void
ks37_midi_connect_get_property (GObject    *object,
				guint       prop_id,
				GValue     *value,
				GParamSpec *pspec)
{
	Ks37MidiConnect *self = KS37_MIDI_CONNECT (object);

	switch (prop_id) {
	case PROP_MIDI_ID:
		g_value_set_uint (value, ks37_midi_connect_get_midi_id (self));
	break;
	default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
	}
}


static void
ks37_midi_connect_set_property (GObject      *object,
				guint         prop_id,
				const GValue *value,
				GParamSpec   *pspec)
{
	Ks37MidiConnect *self = KS37_MIDI_CONNECT (object);

	switch (prop_id) {
	case PROP_MIDI_ID:
		self->midi_id = g_value_get_uint (value);
	break;
	default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
	}
}

static void
ks37_midi_connect_class_init (Ks37MidiConnectClass *klass)
{
	GObjectClass *object_class = G_OBJECT_CLASS (klass);

	object_class->get_property = ks37_midi_connect_get_property;
	object_class->set_property = ks37_midi_connect_set_property;

	value_props[PROP_MIDI_ID] = g_param_spec_uint ("midi-id", NULL, NULL,
		0, G_MAXUINT8, 0,
		G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY);

	g_object_class_install_properties (object_class, LAST_PROP, value_props);
}

static int
ks37_midi_id_idle(void *widget)
{
	Ks37MidiConnect *self = KS37_MIDI_CONNECT (widget);
	GtkWidget *adw_widget, *page_widget, *group_widget;
	uint8_t midi_id = self->midi_id;

	adw_widget = gtk_widget_get_ancestor (GTK_WIDGET (&self->parent_instance), ADW_TYPE_COMBO_ROW);

	if (!adw_widget)
		adw_widget = gtk_widget_get_ancestor (GTK_WIDGET (&self->parent_instance), ADW_TYPE_SPIN_ROW);

	if (!adw_widget)
		adw_widget = gtk_widget_get_ancestor (GTK_WIDGET (&self->parent_instance), ADW_TYPE_SWITCH_ROW);

	page_widget = gtk_widget_get_ancestor (GTK_WIDGET (&self->parent_instance), KS37_TYPE_PREFERENCES_PAGE);
	if (page_widget) {
		midi_id += ks37_preferences_page_get_midi_id_offset (KS37_PREFERENCES_PAGE (page_widget));
	}

	group_widget = gtk_widget_get_ancestor (GTK_WIDGET (&self->parent_instance), KS37_TYPE_PREFERENCES_GROUP);
	if (group_widget)
		midi_id += ks37_preferences_group_get_midi_id_offset (KS37_PREFERENCES_GROUP (group_widget));

	ks37_window_register_control(KS37_WINDOW (gtk_widget_get_root (GTK_WIDGET(adw_widget))), midi_id, adw_widget);

	return false;
}

static void
ks37_midi_id_cb(Ks37MidiConnect *self)
{
	g_idle_add(ks37_midi_id_idle, self);
}

static void
ks37_midi_connect_init (Ks37MidiConnect *self)
{
	gtk_widget_set_visible(GTK_WIDGET (&self->parent_instance), false);
	g_signal_connect(G_OBJECT (self), "notify::midi-id", G_CALLBACK(ks37_midi_id_cb), NULL);
}

