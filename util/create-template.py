#!/usr/bin/env python3

import argparse
import os

parser = argparse.ArgumentParser("create-template")
parser.add_argument("prefix")
parser.add_argument("name")
parser.add_argument("parent_prefix")
parser.add_argument("parent_name")
args = parser.parse_args()


prefix = args.prefix
name = args.name
parent_prefix = args.parent_prefix
parent_name = args.parent_name
dir = os.path.basename(os.getcwd())

typename_big = f'{prefix.upper()}_TYPE_{name.upper()}'
typename_low = f'{prefix.lower()}_{name.lower()}'
typename_low_dash = typename_low.replace("_", "-");
name_capitalized = "".join([a.capitalize() for a in name.split('_')])
full_name_capitalized = prefix.capitalize() + name_capitalized
name_upper = name.upper()
prefix_upper = prefix.upper()
parent_capitalized = parent_prefix.capitalize() + "".join([a.capitalize() for a in parent_name.split('_')])
parent_prefix_upper = parent_prefix.upper()
parent_low = f'{parent_prefix.lower()}_{parent_name.lower()}'
parent_low_dash = parent_low.replace("_", "-")

header = f"""#pragma once

#include <adwaita.h>

#include "{parent_low_dash}.h"

G_BEGIN_DECLS

#define {typename_big} ({typename_low}_get_type ())

G_DECLARE_FINAL_TYPE ({full_name_capitalized}, {typename_low}, {prefix_upper}, {name_upper}, {parent_capitalized})

G_END_DECLS
"""

c = f"""#include "{typename_low_dash}.h"

struct _{full_name_capitalized}
{{
  {parent_capitalized} parent_instance;
}};

G_DEFINE_FINAL_TYPE ({full_name_capitalized}, {typename_low}, {parent_prefix_upper}_TYPE_{parent_name.upper()})

static void
{typename_low}_class_init ({full_name_capitalized}Class *klass)
{{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/hu/irl/sysex-controls/{dir}/{typename_low_dash}.ui");
}}

static void
{typename_low}_init ({full_name_capitalized} *self)
{{
  gtk_widget_init_template (GTK_WIDGET (self));
}}
"""

ui = f"""<?xml version="1.0" encoding="UTF-8"?>
<interface>
  <requires lib="gtk" version="4.0"/>
  <requires lib="libadwaita" version="1.0"/>
  <template class="{full_name_capitalized}" parent="{parent_capitalized}">

  </template>
</interface>
"""

sc_navigation_page_ui = f"""<?xml version="1.0" encoding="UTF-8"?>
<interface>
  <requires lib="gtk" version="4.0"/>
  <requires lib="libadwaita" version="1.0"/>
  <template class="{full_name_capitalized}" parent="{parent_capitalized}">
    <property name="title" translatable="yes">{name_capitalized}</property>
    <property name="child">
      <object class="AdwToolbarView">
        <child type="top"><object class="AdwHeaderBar"/></child>
        <property name="content">
          <object class="ScPreferencesPage">

            <child>
              <object class="AdwPreferencesGroup">

              </object>
            </child>

          </object>
        </property>
      </object>
    </property>

  </template>
</interface>
"""

with open(f'{typename_low_dash}.h', 'w', encoding="utf-8") as f:
    f.write(header)

with open(f'{typename_low_dash}.c', 'w', encoding="utf-8") as f:
    f.write(c)

with open(f'{typename_low_dash}.ui', 'w', encoding="utf-8") as f:
    if parent_low == 'sc_navigation_page':
        f.write(sc_navigation_page_ui)
    else:
        f.write(ui)

