#pragma once

#include <adwaita.h>

#include "ar-book.h"
#include "sc-action-row.h"
#include "sc-navigation-page.h"

#define BSP_MIDI_NAME "Arturia BeatStep Pro"
#define BSP_SHORT_NAME "BS Pro"

G_BEGIN_DECLS

#define BSP_TYPE_BOOK (bsp_book_get_type ())

G_DECLARE_FINAL_TYPE (BspBook, bsp_book, BSP, BOOK, ArBook)

void bsp_book_on_presets_preset_activated (ScNavigationPage *page, ScActionRow *row);

void bsp_book_on_project_settings_activated (ScNavigationPage *page, ScActionRow* row);
void bsp_book_on_project_knobs_activated (ScNavigationPage *page, ScActionRow* row);
void bsp_book_on_project_steps_activated (ScNavigationPage *page, ScActionRow* row);
void bsp_book_on_project_pads_activated (ScNavigationPage *page, ScActionRow* row);
void bsp_book_on_project_sequencer_activated (ScNavigationPage *page, ScActionRow* row);
void bsp_book_on_project_drum_activated (ScNavigationPage *page, ScActionRow* row);

G_END_DECLS
