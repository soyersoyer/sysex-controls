#include "matr-control.h"

#include "matr-book.h"
#include "../sc-control.h"

enum {
    PROP_0,
    PROP_ID,
    LAST_PROP,
};

struct _MatrControl {
    AdwBin parent_instance;
    uint32_t id;
};

static GParamSpec *value_props[LAST_PROP];

static void matr_control_interface_init(ScControlInterface *iface);

G_DEFINE_FINAL_TYPE_WITH_CODE(MatrControl, matr_control, ADW_TYPE_BIN,
                              G_IMPLEMENT_INTERFACE (SC_TYPE_CONTROL, matr_control_interface_init))


uint32_t
matr_control_get_id(MatrControl *self) {
    g_return_val_if_fail(MATR_IS_CONTROL (self), 0);
    return self->id;
}


static void
ar_control_get_property(GObject *object,
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
ar_control_set_property(GObject *object,
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

    object_class->get_property = ar_control_get_property;
    object_class->set_property = ar_control_set_property;

    value_props[PROP_ID] = g_param_spec_uint("id", NULL, NULL,
                                             0, G_MAXUINT32, 0,
                                             G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY);


    g_object_class_install_properties(object_class, LAST_PROP, value_props);
}


static int
matr_control_read_value(ScControl *control) {
    // MatrControl *self = MATR_CONTROL (control);
    // MatrBook *book = MATR_BOOK (gtk_widget_get_ancestor (GTK_WIDGET (self->widget), matr_TYPE_BOOK));
    // uint8_t value;
    // int ret;


    // ret = matr_book_read_control (book, 12, &value);

    return 0;
}

static void
matr_control_update_gui(ScControl *control) {
}

static void
matr_control_interface_init(ScControlInterface *iface) {
    iface->update_gui = matr_control_update_gui;
    iface->read_value = matr_control_read_value;
}

static void
matr_control_init(MatrControl *self) {
}
