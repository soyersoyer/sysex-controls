#pragma once

#include <adwaita.h>

#include "sc-navigation-page.h"

G_BEGIN_DECLS

#define MATR_TYPE_MIDI_PAGE (matr_midi_page_get_type ())

G_DECLARE_FINAL_TYPE (MatrMidiPage, matr_midi_page, MATR, MIDI, ScNavigationPage)

G_END_DECLS
