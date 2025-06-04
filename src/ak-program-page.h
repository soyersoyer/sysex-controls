#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define AK_TYPE_PROGRAM_PAGE (ak_program_page_get_type ())

G_DECLARE_DERIVABLE_TYPE (AkProgramPage, ak_program_page, AK, PROGRAM_PAGE, ScNavigationPage)

struct _AkProgramPageClass
{
  ScNavigationPageClass parent_class;
};

uint8_t ak_program_page_get_prog_id (AkProgramPage *self);

G_END_DECLS
