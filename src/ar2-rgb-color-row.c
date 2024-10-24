#include "ar2-rgb-color-row.h"

enum {
  PROP_0,
  PROP_R,
  PROP_G,
  PROP_B,
  LAST_PROP,
};

static GParamSpec *value_props[LAST_PROP];

struct _Ar2RgbColorRow
{
  AdwActionRow parent_instance;
  GtkColorDialogButton *button;
  AdwSpinRow *r;
  AdwSpinRow *g;
  AdwSpinRow *b;
};

G_DEFINE_FINAL_TYPE (Ar2RgbColorRow, ar2_rgb_color_row, ADW_TYPE_ACTION_ROW)

static void
ar2_rgb_color_row_get_property (GObject    *object,
                                guint       prop_id,
                                GValue     *value,
                                GParamSpec *pspec)
{
  Ar2RgbColorRow *self = AR2_RGB_COLOR_ROW (object);

  switch (prop_id)
    {
      case PROP_R:
        g_value_set_object (value, self->r);
      break;
      case PROP_G:
        g_value_set_object (value, self->g);
      break;
      case PROP_B:
        g_value_set_object (value, self->b);
      break;
      default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}


static void
ar2_rgb_color_row_set_property (GObject      *object,
                                guint         prop_id,
                                const GValue *value,
                                GParamSpec   *pspec)
{
  Ar2RgbColorRow *self = AR2_RGB_COLOR_ROW (object);

  switch (prop_id)
    {
    case PROP_R:
      self->r = g_value_get_object (value);
    break;
    case PROP_G:
      self->g = g_value_get_object (value);
    break;
    case PROP_B:
      self->b = g_value_get_object (value);
    break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}


static void
ar2_rgb_color_row_class_init (Ar2RgbColorRowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->get_property = ar2_rgb_color_row_get_property;
  object_class->set_property = ar2_rgb_color_row_set_property;

  value_props[PROP_R] = g_param_spec_object ("r", NULL, NULL, ADW_TYPE_SPIN_ROW, G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY);
  value_props[PROP_G] = g_param_spec_object ("g", NULL, NULL, ADW_TYPE_SPIN_ROW, G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY);
  value_props[PROP_B] = g_param_spec_object ("b", NULL, NULL, ADW_TYPE_SPIN_ROW, G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY);

  g_object_class_install_properties (object_class, LAST_PROP, value_props);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/ar2-rgb-color-row.ui");
  gtk_widget_class_bind_template_child (widget_class, Ar2RgbColorRow, button);
}

static gboolean
r_to_rgba (GBinding* binding, const GValue* from_value, GValue* to_value, gpointer user_data)
{
  GtkColorDialogButton *target = GTK_COLOR_DIALOG_BUTTON (user_data);
  GdkRGBA rgb = *gtk_color_dialog_button_get_rgba (target);
  rgb.red = g_value_get_double (from_value) / 127;
  g_value_set_boxed (to_value, &rgb);
  return true;
}

static gboolean
rgba_to_r (GBinding* binding, const GValue* from_value, GValue* to_value, gpointer user_data)
{
  GdkRGBA *rgb = g_value_get_boxed (from_value);
  g_value_set_double (to_value, rgb->red * 127);
  return true;
}

static gboolean
g_to_rgba (GBinding* binding, const GValue* from_value, GValue* to_value, gpointer user_data)
{
  GtkColorDialogButton *target = GTK_COLOR_DIALOG_BUTTON (user_data);
  GdkRGBA rgb = *gtk_color_dialog_button_get_rgba (target);
  rgb.green = g_value_get_double (from_value) / 127;
  g_value_set_boxed (to_value, &rgb);
  return true;
}

static gboolean
rgba_to_g (GBinding* binding, const GValue* from_value, GValue* to_value, gpointer user_data)
{
  GdkRGBA *rgb = g_value_get_boxed (from_value);
  g_value_set_double (to_value, rgb->green * 127);
  return true;
}

static gboolean
b_to_rgba (GBinding* binding, const GValue* from_value, GValue* to_value, gpointer user_data)
{
  GtkColorDialogButton *target = GTK_COLOR_DIALOG_BUTTON (user_data);
  GdkRGBA rgb = *gtk_color_dialog_button_get_rgba (target);
  rgb.blue = g_value_get_double (from_value) / 127;
  g_value_set_boxed (to_value, &rgb);
  return true;
}

static gboolean
rgba_to_b (GBinding* binding, const GValue* from_value, GValue* to_value, gpointer user_data)
{
  GdkRGBA *rgb = g_value_get_boxed (from_value);
  g_value_set_double (to_value, rgb->blue * 127);
  return true;
}

static int
bind_sources(Ar2RgbColorRow *self)
{
  g_object_bind_property_full (self->r, "value", self->button, "rgba", G_BINDING_SYNC_CREATE | G_BINDING_BIDIRECTIONAL, r_to_rgba, rgba_to_r, self->button, NULL);
  g_object_bind_property_full (self->g, "value", self->button, "rgba", G_BINDING_SYNC_CREATE | G_BINDING_BIDIRECTIONAL, g_to_rgba, rgba_to_g, self->button, NULL);
  g_object_bind_property_full (self->b, "value", self->button, "rgba", G_BINDING_SYNC_CREATE | G_BINDING_BIDIRECTIONAL, b_to_rgba, rgba_to_b, self->button, NULL);
  return 0;
}

static void
ar2_rgb_color_row_init (Ar2RgbColorRow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));

  g_idle_add (G_SOURCE_FUNC (bind_sources), self);
}
