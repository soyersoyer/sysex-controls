#include "sc-note-row.h"
#include "sc-control-value.h"

#define MAX_NOTE 127

enum {
  PROP_0,
  PROP_MAX_VALUE,
  LAST_PROP,
};

static GParamSpec *value_props[LAST_PROP];

struct _ScNoteRow
{
  ScComboRow parent_instance;
  uint8_t max_value;
};

G_DEFINE_FINAL_TYPE (ScNoteRow, sc_note_row, SC_TYPE_COMBO_ROW)

static void
sc_note_row_get_property (GObject    *object,
                          guint       prop_id,
                          GValue     *value,
                          GParamSpec *pspec)
{
  ScNoteRow *self = SC_NOTE_ROW (object);

  switch (prop_id)
    {
      case PROP_MAX_VALUE:
        g_value_set_uint (value, self->max_value);
      break;
      default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}


static void
sc_note_row_set_property (GObject      *object,
                          guint         prop_id,
                          const GValue *value,
                          GParamSpec   *pspec)
{
  ScNoteRow *self = SC_NOTE_ROW (object);

  switch (prop_id)
    {
    case PROP_MAX_VALUE:
      self->max_value = g_value_get_uint (value);
    break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}


static void
sc_note_row_class_init (ScNoteRowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->get_property = sc_note_row_get_property;
  object_class->set_property = sc_note_row_set_property;

  value_props[PROP_MAX_VALUE] = g_param_spec_uint ("max-value", NULL, NULL,
                                                   0, MAX_NOTE, MAX_NOTE,
                                                   G_PARAM_READWRITE);

  g_object_class_install_properties (object_class, LAST_PROP, value_props);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/sc-note-row.ui");
}

static int
set_max_value (ScNoteRow *self)
{
  GListModel *model = adw_combo_row_get_model (ADW_COMBO_ROW (self));
  sc_control_value_list_splice (SC_CONTROL_VALUE_LIST (model), self->max_value + 1, MAX_NOTE - self->max_value, NULL, 0);
  return false;
}

static void
sc_note_row_init (ScNoteRow *self)
{
  self->max_value = 127;
  gtk_widget_init_template (GTK_WIDGET (self));
  g_idle_add (G_SOURCE_FUNC (set_max_value), self);
}
