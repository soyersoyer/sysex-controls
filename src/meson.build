sc_sources = [
  'sc-application.c',
  'sc-combo-row.c',
  'sc-control-value.c',
  'sc-midi.c',
  'sc-midi-connect.c',
  'sc-preferences-group.c',
  'sc-preferences-page.c',
  'sc-window.c',
  'main.c',
  'keystep37/ks37-book.c',
  'keystep37/ks37-page-cc-bank.c',
  'keystep37/ks37-page-cc-bank-knob.c',
  'keystep37/ks37-page-controller.c',
  'keystep37/ks37-page-cv-gate.c',
  'keystep37/ks37-page-sequence.c',
  'keystep37/ks37-page-transport.c',
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
