#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define MATR_TYPE_ARP_SEQ_PAGE (matr_arp_seq_page_get_type ())

G_DECLARE_FINAL_TYPE (MatrArpSeqPage, matr_arp_seq_page, MATR, ARP_SEQ_PAGE, ScNavigationPage)

G_END_DECLS
