#pragma once

#include <adwaita.h>

G_BEGIN_DECLS

#define SC_TYPE_NAVIGATION_PAGE (sc_navigation_page_get_type ())

G_DECLARE_DERIVABLE_TYPE (ScNavigationPage, sc_navigation_page, SC, NAVIGATION_PAGE, AdwNavigationPage)

struct _ScNavigationPageClass
{
  AdwNavigationPageClass parent_class;
};

uint32_t sc_navigation_page_get_control_id_offset (ScNavigationPage *self);
uint32_t sc_navigation_page_get_control_cc_offset (ScNavigationPage *self);

G_END_DECLS
