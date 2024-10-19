#include "sc-navigation-page.h"

#include "sc-window.h"

enum {
  PROP_0,
  PROP_CONTROL_ID_OFFSET,
  PROP_CONTROL_CC_OFFSET,
  LAST_PROP,
};

static GParamSpec *value_props[LAST_PROP];

typedef struct
{
  uint32_t control_id_offset;
  uint32_t control_cc_offset;
  GListStore *controls;
} ScNavigationPagePrivate;


G_DEFINE_TYPE_WITH_PRIVATE (ScNavigationPage, sc_navigation_page, ADW_TYPE_NAVIGATION_PAGE)

uint32_t
sc_navigation_page_get_control_id_offset (ScNavigationPage *self)
{
  ScNavigationPagePrivate *priv = sc_navigation_page_get_instance_private (self);
  return priv->control_id_offset;
}

uint32_t
sc_navigation_page_get_control_cc_offset (ScNavigationPage *self)
{
  ScNavigationPagePrivate *priv = sc_navigation_page_get_instance_private (self);
  return priv->control_cc_offset;
}

static void
sc_navigation_page_get_property (GObject    *object,
                                 guint       prop_id,
                                 GValue     *value,
                                 GParamSpec *pspec)
{
  ScNavigationPage *self = SC_NAVIGATION_PAGE (object);

  switch (prop_id)
    {
      case PROP_CONTROL_ID_OFFSET:
        g_value_set_uint (value, sc_navigation_page_get_control_id_offset (self));
      break;
      case PROP_CONTROL_CC_OFFSET:
        g_value_set_uint (value, sc_navigation_page_get_control_cc_offset (self));
      break;
      default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}


static void
sc_navigation_page_set_property (GObject      *object,
                                 guint         prop_id,
                                 const GValue *value,
                                 GParamSpec   *pspec)
{
  ScNavigationPage *self = SC_NAVIGATION_PAGE (object);
  ScNavigationPagePrivate *priv = sc_navigation_page_get_instance_private (self);

  switch (prop_id)
    {
    case PROP_CONTROL_ID_OFFSET:
      priv->control_id_offset = g_value_get_uint (value);
    break;
    case PROP_CONTROL_CC_OFFSET:
      priv->control_cc_offset = g_value_get_uint (value);
    break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}


static void
sc_navigation_page_class_init (ScNavigationPageClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->get_property = sc_navigation_page_get_property;
  object_class->set_property = sc_navigation_page_set_property;

  value_props[PROP_CONTROL_ID_OFFSET] = g_param_spec_uint ("control-id-offset", NULL, NULL,
                                                           0, G_MAXUINT32, 0,
                                                           G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY);

  value_props[PROP_CONTROL_CC_OFFSET] = g_param_spec_uint ("control-cc-offset", NULL, NULL,
                                                           0, G_MAXUINT32, 0,
                                                           G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY);

  g_object_class_install_properties (object_class, LAST_PROP, value_props);
}

static void
sc_navigation_page_init (ScNavigationPage *self)
{
  ScNavigationPagePrivate *priv = sc_navigation_page_get_instance_private (self);
  priv->controls = g_list_store_new (SC_TYPE_CONTROL);
}

void
sc_navigation_page_register_control (ScNavigationPage *self, ScControl *control)
{
  ScNavigationPagePrivate *priv = sc_navigation_page_get_instance_private (self);

  g_list_store_append (priv->controls, control);

  g_debug ("sc_navigation_page_register_control %s", gtk_widget_get_name (GTK_WIDGET (control)));
}

int
sc_navigation_page_load_controls (ScNavigationPage *self)
{
  ScNavigationPagePrivate *priv = sc_navigation_page_get_instance_private (self);
  GListModel *list = G_LIST_MODEL (priv->controls);

  for(int i = 0; i < g_list_model_get_n_items (list); ++i)
  {
    int err = sc_control_read_value (SC_CONTROL (g_list_model_get_item (list, i)));
    if (err < 0)
      return err;
  }
  return 0;
}

void
sc_navigation_page_update_gui (ScNavigationPage *self)
{
  ScNavigationPagePrivate *priv = sc_navigation_page_get_instance_private (self);
  GListModel *list = G_LIST_MODEL (priv->controls);

  for(int i = 0; i < g_list_model_get_n_items (list); ++i)
    sc_control_update_gui (SC_CONTROL (g_list_model_get_item (list, i)));
}

static void
sc_navigation_page_load_task (GTask *task, gpointer source_obj, gpointer task_data, GCancellable *cancellable)
{
  AdwNavigationPage *self = ADW_NAVIGATION_PAGE (source_obj);

  g_debug ("sc_navigation_page_load_task start");
  if (sc_navigation_page_load_controls (SC_NAVIGATION_PAGE (self)) < 0)
  {
    g_task_return_new_error_literal (task, G_IO_ERROR, G_IO_ERROR_FAILED, "control value read failed");
    return;
  }

  g_task_return_boolean (task, true);
  g_debug ("sc_navigation_page_load_task end");
}

static void
sc_navigation_page_load_task_finish (GObject* source_object, GAsyncResult* res, gpointer data)
{
  AdwNavigationPage *self = ADW_NAVIGATION_PAGE (source_object);

  ScWindow *window = SC_WINDOW (gtk_widget_get_root (GTK_WIDGET (source_object)));
  GError *error = NULL;
  g_task_propagate_boolean (G_TASK (res), &error);

  if (error)
  {
    sc_io_problem (window, "%s", error->message);
    return;
  }
  sc_navigation_page_update_gui (SC_NAVIGATION_PAGE (self));
}

int
sc_navigation_page_load_controls_and_update_bg (ScNavigationPage *self)
{
  GTask *task = g_task_new (self, NULL, sc_navigation_page_load_task_finish, NULL);
  g_task_run_in_thread (task, sc_navigation_page_load_task);
  g_object_unref (task);

  return false;
}
