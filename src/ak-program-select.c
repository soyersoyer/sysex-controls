#include "ak-program-select.h"

#include "ak-book.h"
#include "ak-program-page.h"
#include "sc-window.h"

struct _AkProgramSelect
{
  GtkButton parent_instance;
};

G_DEFINE_FINAL_TYPE (AkProgramSelect, ak_program_select, GTK_TYPE_BUTTON)

static void
ak_program_select_class_init (AkProgramSelectClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/ak-program-select.ui");
}

static int
set_visible (AkProgramSelect *self)
{
  AkProgramPage *page = AK_PROGRAM_PAGE (gtk_widget_get_ancestor (GTK_WIDGET (self), AK_TYPE_PROGRAM_PAGE));
  gtk_widget_set_visible (GTK_WIDGET (self), ak_program_page_get_prog_id (page));
  return 0;
}

static void
ak_program_select_init (AkProgramSelect *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
  g_idle_add (G_SOURCE_FUNC (set_visible), self);
}

void
ak_program_select_clicked (AkProgramSelect *self)
{
  AkBook *book = AK_BOOK (gtk_widget_get_ancestor (GTK_WIDGET (self), AK_TYPE_BOOK));
  AkProgramPage *page = AK_PROGRAM_PAGE (gtk_widget_get_ancestor (GTK_WIDGET (self), AK_TYPE_PROGRAM_PAGE));
  uint8_t prog_id = ak_program_page_get_prog_id (page);
  ScWindow *window = SC_WINDOW (gtk_widget_get_root (GTK_WIDGET (self)));
  if (ak_book_select_program (book, prog_id) < 0)
  {
    sc_io_problem (window, "Program select failed");
  }
  // refresh ram page
  ak_book_refresh_page (book, 0);
}
