#include "korg-scene-row.h"

enum {
  PROP_0,
  PROP_SCENE_ID,
  PROP_SCENE_CHANGE,
  PROP_TARGET_PAGE,
  LAST_PROP,
};

static GParamSpec *value_props[LAST_PROP];

struct _KorgSceneRow
{
  AdwActionRow parent_instance;
  uint8_t scene_id;
  gboolean scene_change;
  GType target_page;
};

G_DEFINE_FINAL_TYPE (KorgSceneRow, korg_scene_row, ADW_TYPE_ACTION_ROW)

uint8_t 
korg_scene_row_get_scene_id (KorgSceneRow *self)
{
  return self->scene_id;
}

gboolean
korg_scene_row_get_scene_change (KorgSceneRow *self)
{
  return self->scene_change;
}

GType
korg_scene_row_get_target_page (KorgSceneRow *self)
{
  return self->target_page;
}

static void
korg_scene_row_get_property (GObject    *object,
                             guint       prop_id,
                             GValue     *value,
                             GParamSpec *pspec)
{
  KorgSceneRow *self = KORG_SCENE_ROW (object);

  switch (prop_id)
    {
      case PROP_SCENE_ID:
        g_value_set_uint (value, korg_scene_row_get_scene_id (self));
      break;
      case PROP_SCENE_CHANGE:
        g_value_set_boolean (value, korg_scene_row_get_scene_change (self));
      break;
      case PROP_TARGET_PAGE:
        g_value_set_gtype (value, korg_scene_row_get_target_page (self));
      break;
      default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}


static void
korg_scene_row_set_property (GObject      *object,
                             guint         prop_id,
                             const GValue *value,
                             GParamSpec   *pspec)
{
  KorgSceneRow *self = KORG_SCENE_ROW (object);

  switch (prop_id)
    {
    case PROP_SCENE_ID:
      self->scene_id = g_value_get_uint (value);
    break;
    case PROP_SCENE_CHANGE:
      self->scene_change = g_value_get_boolean (value);
    break;
    case PROP_TARGET_PAGE:
      self->target_page = g_value_get_gtype (value);
    break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}

static void
korg_scene_row_class_init (KorgSceneRowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->get_property = korg_scene_row_get_property;
  object_class->set_property = korg_scene_row_set_property;

  value_props[PROP_SCENE_ID] = g_param_spec_uint ("scene-id", NULL, NULL,
                                                           0, G_MAXUINT8, 0,
                                                           G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY);

  value_props[PROP_SCENE_CHANGE] = g_param_spec_boolean ("scene-change", NULL, NULL,
                                                          0,
                                                          G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY);

  value_props[PROP_TARGET_PAGE] = g_param_spec_gtype ("target-page", NULL, NULL,
                                                      G_TYPE_NONE,
                                                      G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY);

  g_object_class_install_properties (object_class, LAST_PROP, value_props);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/korg-scene-row.ui");
}

static void
korg_scene_row_init (KorgSceneRow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}

void
korg_scene_nav_push (KorgSceneRow *row, ScNavigationPage *page)
{
  GType target_page = korg_scene_row_get_target_page (row);
  AdwNavigationView *view = ADW_NAVIGATION_VIEW (gtk_widget_get_ancestor (GTK_WIDGET (page), ADW_TYPE_NAVIGATION_VIEW));
  AdwNavigationPage *nav_page = g_object_new (target_page,
                                              "title", adw_preferences_row_get_title (ADW_PREFERENCES_ROW (row)),
                                              "scene-id", korg_scene_row_get_scene_id (row),
                                              "scene-change", korg_scene_row_get_scene_change (row),
                                              NULL);
  adw_navigation_view_push (view, nav_page);
  g_idle_add (G_SOURCE_FUNC (sc_navigation_page_load_controls_and_update_bg), nav_page);
}
