#include "ar2-user-scale.h"

enum {
  PROP_0,
  PROP_PART,
  PROP_VALUE,
  LAST_PROP,
};

static GParamSpec *value_props[LAST_PROP];

struct _Ar2UserScale
{
  GtkBox parent_instance;
  uint8_t part;
  GtkToggleButton *b0;
  GtkToggleButton *b1;
  GtkToggleButton *b2;
  GtkToggleButton *b3;
  GtkToggleButton *b4;
  GtkToggleButton *b5;
};

G_DEFINE_FINAL_TYPE (Ar2UserScale, ar2_user_scale, GTK_TYPE_BOX)

uint8_t
ar2_user_scale_get_part (Ar2UserScale *self)
{
  return self->part;
}

void
ar2_user_scale_set_part (Ar2UserScale *self, uint8_t part)
{
  self->part = part;
  switch (self->part)
    {
    case 0:
      gtk_button_set_label (GTK_BUTTON (self->b0), "C");
      gtk_widget_set_sensitive (GTK_WIDGET (self->b0), false);
      gtk_button_set_label (GTK_BUTTON (self->b1), "C#");
      gtk_button_set_label (GTK_BUTTON (self->b2), "D");
      gtk_button_set_label (GTK_BUTTON (self->b3), "D#");
      gtk_button_set_label (GTK_BUTTON (self->b4), "E");
      gtk_button_set_label (GTK_BUTTON (self->b5), "F");
      break;
    case 1:
    default:
      gtk_button_set_label (GTK_BUTTON (self->b0), "F#");
      gtk_button_set_label (GTK_BUTTON (self->b1), "G");
      gtk_button_set_label (GTK_BUTTON (self->b2), "G#");
      gtk_button_set_label (GTK_BUTTON (self->b3), "A");
      gtk_button_set_label (GTK_BUTTON (self->b4), "A#");
      gtk_button_set_label (GTK_BUTTON (self->b5), "B");
    }

  g_object_notify_by_pspec (G_OBJECT (self), value_props[PROP_PART]);
}

uint8_t
ar2_user_scale_get_value (Ar2UserScale *self)
{
  return
    gtk_toggle_button_get_active (self->b0) << 0 |
    gtk_toggle_button_get_active (self->b1) << 1 |
    gtk_toggle_button_get_active (self->b2) << 2 |
    gtk_toggle_button_get_active (self->b3) << 3 |
    gtk_toggle_button_get_active (self->b4) << 4 |
    gtk_toggle_button_get_active (self->b5) << 5;
}

void
ar2_user_scale_set_value (Ar2UserScale *self, uint8_t value)
{
  if (self->part == 0)
    value |= 1;

  gtk_toggle_button_set_active (self->b0, value & (1 << 0));
  gtk_toggle_button_set_active (self->b1, value & (1 << 1));
  gtk_toggle_button_set_active (self->b2, value & (1 << 2));
  gtk_toggle_button_set_active (self->b3, value & (1 << 3));
  gtk_toggle_button_set_active (self->b4, value & (1 << 4));
  gtk_toggle_button_set_active (self->b5, value & (1 << 5));
}

static void
ar2_user_scale_get_property (GObject    *object,
                             guint       prop_id,
                             GValue     *value,
                             GParamSpec *pspec)
{
  Ar2UserScale *self = AR2_USER_SCALE (object);

  switch (prop_id)
    {
      case PROP_PART:
        g_value_set_uint (value, ar2_user_scale_get_part (self));
      break;
      case PROP_VALUE:
        g_value_set_uint (value, ar2_user_scale_get_value (self));
      break;
      default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}

static void
ar2_user_scale_set_property (GObject      *object,
                             guint         prop_id,
                             const GValue *value,
                             GParamSpec   *pspec)
{
  Ar2UserScale *self = AR2_USER_SCALE (object);

  switch (prop_id)
    {
    case PROP_PART:
      ar2_user_scale_set_part (self, g_value_get_uint (value));
    break;
    case PROP_VALUE:
      ar2_user_scale_set_value (self, g_value_get_uint (value));
    break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}

static void
ar2_user_scale_class_init (Ar2UserScaleClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->get_property = ar2_user_scale_get_property;
  object_class->set_property = ar2_user_scale_set_property;

  value_props[PROP_PART] = g_param_spec_uint ("part", NULL, NULL,
                                               0, G_MAXUINT8, 0,
                                               G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY);

  value_props[PROP_VALUE] = g_param_spec_uint ("value", NULL, NULL,
                                               0, G_MAXUINT8, 0,
                                               G_PARAM_READWRITE | G_PARAM_EXPLICIT_NOTIFY);

  g_object_class_install_properties (object_class, LAST_PROP, value_props);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/ar2-user-scale.ui");

  gtk_widget_class_bind_template_child (widget_class, Ar2UserScale, b0);
  gtk_widget_class_bind_template_child (widget_class, Ar2UserScale, b1);
  gtk_widget_class_bind_template_child (widget_class, Ar2UserScale, b2);
  gtk_widget_class_bind_template_child (widget_class, Ar2UserScale, b3);
  gtk_widget_class_bind_template_child (widget_class, Ar2UserScale, b4);
  gtk_widget_class_bind_template_child (widget_class, Ar2UserScale, b5);
}

static void
ar2_user_scale_init (Ar2UserScale *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}

void
ar2_user_scale_toggle_cb (Ar2UserScale *self, GtkToggleButton *btn)
{
  g_object_notify_by_pspec (G_OBJECT (self), value_props[PROP_VALUE]);
}
