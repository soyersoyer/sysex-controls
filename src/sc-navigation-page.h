#pragma once

#include <adwaita.h>

#include "sc-arturia-control.h"

G_BEGIN_DECLS

#define SC_TYPE_NAVIGATION_PAGE (sc_navigation_page_get_type ())

G_DECLARE_DERIVABLE_TYPE (ScNavigationPage, sc_navigation_page, SC, NAVIGATION_PAGE, AdwNavigationPage)

struct _ScNavigationPageClass
{
  AdwNavigationPageClass parent_class;
};

uint32_t sc_navigation_page_get_control_id_offset (ScNavigationPage *self);
uint32_t sc_navigation_page_get_control_cc_offset (ScNavigationPage *self);
void sc_navigation_page_register_control (ScNavigationPage *self, uint32_t control_id, uint32_t real_id, ScArturiaControl *control);
int sc_navigation_page_load_controls (ScNavigationPage *self);
void sc_navigation_page_update_gui (ScNavigationPage *self);
int sc_navigation_page_load_controls_and_update_bg (ScNavigationPage *self);

G_END_DECLS
