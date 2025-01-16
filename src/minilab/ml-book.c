#include "ml-book.h"

#include "ml-controller-page.h"
#include "ml-velocity-page.h"

struct _MlBook
{
  ArBook parent_instance;
};

G_DEFINE_FINAL_TYPE (MlBook, ml_book, AR_TYPE_BOOK)

static void
ml_book_class_init (MlBookClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/minilab/ml-book.ui");
}

static void
ml_book_init (MlBook *self)
{
  g_type_ensure (ML_TYPE_CONTROLLER_PAGE);
  g_type_ensure (ML_TYPE_VELOCITY_PAGE);

  gtk_widget_init_template (GTK_WIDGET (self));
}
