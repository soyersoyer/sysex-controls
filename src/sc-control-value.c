#include "sc-control-value.h"

enum {
  PROP_0,
  PROP_VALUE,
  PROP_NAME,
  LAST_PROP,
};


struct _ScControlValue
{
  GObject    parent_instance;
  uint8_t    value;
  char       *name;
};

struct _ScControlValueClass
{
  GObjectClass parent_class;
};

static GParamSpec *value_props[LAST_PROP];


G_DEFINE_TYPE (ScControlValue, sc_control_value, G_TYPE_OBJECT)

static void
sc_control_value_init(ScControlValue *item)
{
}

static void
sc_control_value_finalize (GObject *object)
{
  ScControlValue *self = SC_CONTROL_VALUE (object);

  g_free (self->name);

  G_OBJECT_CLASS (sc_control_value_parent_class)->finalize (object);
}


int
sc_control_value_get_value (ScControlValue *self)
{
  g_return_val_if_fail (SC_IS_CONTROL_VALUE (self), 0);

  return self->value;
}

const char*
sc_control_value_get_name (ScControlValue *self)
{
  g_return_val_if_fail (SC_IS_CONTROL_VALUE (self), 0);
  return self->name;
}


static void
sc_control_value_get_property (GObject    *object,
                               guint       prop_id,
                               GValue     *value,
                               GParamSpec *pspec)
{
  ScControlValue *self = SC_CONTROL_VALUE (object);

  switch (prop_id)
    {
    case PROP_VALUE:
      g_value_set_int (value, sc_control_value_get_value (self));
    break;

    case PROP_NAME:
      g_value_set_string (value, sc_control_value_get_name (self));
    break;

    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}


static void
sc_control_value_set_property (GObject      *object,
                               guint         prop_id,
                               const GValue *value,
                               GParamSpec   *pspec)
{
  ScControlValue *self = SC_CONTROL_VALUE (object);

  switch (prop_id)
    {
    case PROP_VALUE:
      self->value = g_value_get_int (value);
    break;

    case PROP_NAME:
      self->name = g_value_dup_string (value);
    break;

    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}



static void
sc_control_value_class_init (ScControlValueClass *class)
{
  GObjectClass *object_class = G_OBJECT_CLASS (class);
  object_class->finalize = sc_control_value_finalize;
  object_class->get_property = sc_control_value_get_property;
  object_class->set_property = sc_control_value_set_property;

  value_props[PROP_VALUE] = g_param_spec_int ("value", NULL, NULL,
					      G_MININT, G_MAXINT, 0,
					      G_PARAM_READWRITE);

  value_props[PROP_NAME] = g_param_spec_string ("name", NULL, NULL,
						NULL,
						G_PARAM_READWRITE);

  g_object_class_install_properties (object_class, LAST_PROP, value_props);
}

ScControlValue*
sc_control_value_new (uint8_t value, const char *name)
{
  ScControlValue  *cv = g_object_new (SC_TYPE_CONTROL_VALUE, NULL);
  cv->value = value;
  cv->name = g_strdup (name);
  return cv;
}

struct _ScControlValueList
{
  GObject parent_instance;
  GListStore *store;
};

struct _ScControlValueListClass
{
  GObjectClass parent_class;
};


static GType
sc_control_value_list_get_item_type (GListModel *list)
{
  return G_TYPE_OBJECT;
}

static guint
sc_control_value_list_get_n_items (GListModel *list)
{
  ScControlValueList *self = SC_CONTROL_VALUE_LIST (list);

  return g_list_model_get_n_items (G_LIST_MODEL (self->store));
}

static gpointer
sc_control_value_list_get_item (GListModel *list, guint position)
{
  ScControlValueList *self = SC_CONTROL_VALUE_LIST (list);

  return g_list_model_get_item (G_LIST_MODEL (self->store), position);
}

static void
sc_control_value_list_model_init (GListModelInterface *iface)
{
  iface->get_item_type = sc_control_value_list_get_item_type;
  iface->get_n_items = sc_control_value_list_get_n_items;
  iface->get_item = sc_control_value_list_get_item;
}

static gboolean
gtk_builder_check_parents (GtkBuilder                *builder,
                           GtkBuildableParseContext  *context,
                           GError                   **error,
                           ...)
{
  GPtrArray *stack;
  int line, col;
  const char *parent;
  const char *element;
  va_list args;
  gboolean in_template;

  stack = gtk_buildable_parse_context_get_element_stack (context);

  element = g_ptr_array_index (stack, stack->len - 1);
  parent = stack->len > 1 ? g_ptr_array_index (stack, stack->len - 2) : "";

  in_template = g_str_equal (parent, "template");

  va_start (args, error);

  while (1)
  {
    char *parent_name = va_arg (args, char *);

    if (parent_name == NULL)
      break;

    if (g_str_equal (parent_name, parent) || (in_template && g_str_equal (parent_name, "object")))
    {
      va_end (args);
      return TRUE;
    }
  }

  va_end (args);

  gtk_buildable_parse_context_get_position (context, &line, &col);
  g_set_error (error,
               GTK_BUILDER_ERROR,
               GTK_BUILDER_ERROR_INVALID_TAG,
               "%d:%d Can't use <%s> here", line, col, element);

  return FALSE;
}

static gboolean
gtk_builder_check_parent (GtkBuilder                *builder,
                          GtkBuildableParseContext  *context,
                          const char                *parent_name,
                          GError                   **error)
{
  return gtk_builder_check_parents (builder, context, error, parent_name, NULL);
}

static void
gtk_builder_prefix_error (GtkBuilder                *builder,
                          GtkBuildableParseContext  *context,
                          GError                   **error)
{
  int line, col;

  gtk_buildable_parse_context_get_position (context, &line, &col);
  g_prefix_error (error, "%d:%d ", line, col);
}

static void
gtk_builder_error_unhandled_tag (GtkBuilder                *builder,
                                 GtkBuildableParseContext  *context,
                                 const char                *object,
                                 const char                *element_name,
                                 GError                   **error)
{
  int line, col;

  gtk_buildable_parse_context_get_position (context, &line, &col);
  g_set_error (error,
               GTK_BUILDER_ERROR,
               GTK_BUILDER_ERROR_UNHANDLED_TAG,
               "%d:%d Unsupported tag for %s: <%s>", line, col,
               object, element_name);
}

typedef struct
{
  GtkBuilder    *builder;
  GListStore    *list;
  GString       *name;
  guint          value;

  guint          is_control_value : 1;
} ItemParserData;

static void
item_start_element (GtkBuildableParseContext  *context,
                    const char                *element_name,
                    const char               **names,
                    const char               **values,
                    gpointer                   user_data,
                    GError                   **error)
{
  ItemParserData *data = (ItemParserData*)user_data;

  if (strcmp (element_name, "items") == 0)
  {
    if (!gtk_builder_check_parent (data->builder, context, "object", error))
      return;

    if (!g_markup_collect_attributes (element_name, names, values, error,
                                      G_MARKUP_COLLECT_INVALID, NULL, NULL,
                                      G_MARKUP_COLLECT_INVALID))
      gtk_builder_prefix_error (data->builder, context, error);
  }
  else if (strcmp (element_name, "item") == 0)
  {
    const char *value = NULL;
    guint v;
    gchar* vptr;

    if (!gtk_builder_check_parent (data->builder, context, "items", error))
      return;

    if (!g_markup_collect_attributes (element_name, names, values, error,
                                      G_MARKUP_COLLECT_STRING|G_MARKUP_COLLECT_OPTIONAL, "value", &value,
                                      G_MARKUP_COLLECT_INVALID))
    {
      gtk_builder_prefix_error (data->builder, context, error);
      return;
    }

    data->is_control_value = TRUE;
    if (value)
    {
      v = g_ascii_strtoll (value, &vptr, 16);
      if (!errno && vptr != value)
        data->value = v;
    }
  }
  else
  {
    gtk_builder_error_unhandled_tag (data->builder, context,
                                     "ScControlValueList", element_name,
                                     error);
  }
}

static void
item_text (GtkBuildableParseContext  *context,
           const char                *text,
           gsize                      text_len,
           gpointer                   user_data,
           GError                   **error)
{
  ItemParserData *data = (ItemParserData*)user_data;

  if (data->is_control_value)
    g_string_append_len (data->name, text, text_len);
}

static void
item_end_element (GtkBuildableParseContext  *context,
                  const char                *element_name,
                  gpointer                   user_data,
                  GError                   **error)
{
  ItemParserData *data = (ItemParserData*)user_data;

  if (data->name->len)
  {
    g_list_store_append (data->list, sc_control_value_new(data->value, data->name->str));
    data->value++;
  }

  g_string_set_size (data->name, 0);
  data->is_control_value = FALSE;
}

static const GtkBuildableParser item_parser =
{
  item_start_element,
  item_end_element,
  item_text
};


static gboolean
sc_control_value_list_buildable_custom_tag_start (GtkBuildable       *buildable,
                                                  GtkBuilder         *builder,
                                                  GObject            *child,
                                                  const char         *tagname,
                                                  GtkBuildableParser *parser,
                                                  gpointer           *parser_data)
{
  if (strcmp (tagname, "items") == 0)
  {
    ItemParserData *data;

    data = g_new0 (ItemParserData, 1);
    data->builder = g_object_ref (builder);
    data->list = g_object_ref (SC_CONTROL_VALUE_LIST (buildable)->store);
    data->name = g_string_new ("");
    data->value = 0;

    *parser = item_parser;
    *parser_data = data;
    return TRUE;
  }

  return FALSE;
}

static void
sc_control_value_list_buildable_custom_finished (GtkBuildable *buildable,
                                                 GtkBuilder   *builder,
                                                 GObject      *child,
                                                 const char   *tagname,
                                                 gpointer      user_data)
{
  if (strcmp (tagname, "items") == 0)
  {
    ItemParserData *data;

    data = (ItemParserData*)user_data;
    g_object_unref (data->list);
    g_object_unref (data->builder);
    g_string_free (data->name, TRUE);
    g_free (data);
  }
}


static void
sc_control_value_list_buildable_init (GtkBuildableIface *iface)
{
  iface->custom_tag_start = sc_control_value_list_buildable_custom_tag_start;
  iface->custom_finished = sc_control_value_list_buildable_custom_finished;
}


G_DEFINE_TYPE_WITH_CODE (ScControlValueList, sc_control_value_list, G_TYPE_OBJECT,
                         G_IMPLEMENT_INTERFACE (GTK_TYPE_BUILDABLE,
                                                sc_control_value_list_buildable_init)
                         G_IMPLEMENT_INTERFACE (G_TYPE_LIST_MODEL,
                                                sc_control_value_list_model_init))

G_MODULE_EXPORT gboolean
cv_in (GObject *object, ScControlValue* value, GVariant* variant)
{
  int selected = sc_control_value_get_value (value);
  const gint *array = NULL;
  gsize n_elements;

  array = g_variant_get_fixed_array (variant, &n_elements, sizeof(gint));
  for (int i = 0; i < n_elements; ++i)
    if (array[i] == selected)
      return TRUE;

  return FALSE;
}

static void
sc_control_value_list_init (ScControlValueList *self)
{
  self->store = g_list_store_new(G_TYPE_OBJECT);
}

static void
sc_control_value_list_class_init (ScControlValueListClass *class)
{
}
