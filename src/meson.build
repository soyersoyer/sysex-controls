sc_sources = [
  'sc-application.c',
  'sc-cc-row.c',
  'sc-combo-row.c',
  'sc-control-value.c',
  'sc-midi.c',
  'sc-midi-connect.c',
  'sc-preferences-group.c',
  'sc-preferences-page.c',
  'sc-window.c',
  'main.c',
  'keystep37/ks37-book.c',
  'keystep37/ks37-cc-bank-knob.c',
  'keystep37/ks37-cc-bank-page.c',
  'keystep37/ks37-controller-page.c',
  'keystep37/ks37-cv-gate-page.c',
  'keystep37/ks37-note-row.c',
  'keystep37/ks37-sequence-page.c',
  'keystep37/ks37-transport-page.c',
  'minilab2/ml2-book.c',
  'minilab2/ml2-color-row.c',
]

sc_deps = [
  dependency('gtk4'),
  dependency('libadwaita-1', version: '>= 1.4'),
  dependency('alsa'),
  dependency('gmodule-export-2.0'),
]

sc_sources += gnome.compile_resources('sc-resources',
  'sc.gresource.xml',
  c_name: 'sc'
)

executable('sysex-controls', sc_sources,
  dependencies: sc_deps,
       install: true,
)
