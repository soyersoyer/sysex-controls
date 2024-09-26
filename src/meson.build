ks37_sources = [
  'main.c',
  'ks37-application.c',
  'ks37-window.c',
  'ks37-midi.c',
  'ks37-book.c',
  'ks37-control-value.c',
  'ks37-combo-row.c',
  'ks37-preferences-page.c',
  'ks37-preferences-group.c',
  'ks37-midi-connect.c',
  'pages/cc-bank/ks37-page-cc-bank.c',
  'pages/cc-bank/ks37-page-cc-bank-knob.c',
  'pages/controller/ks37-page-controller.c',
  'pages/cv-gate/ks37-page-cv-gate.c',
  'pages/sequence/ks37-page-sequence.c',
  'pages/transport/ks37-page-transport.c',
]

ks37_deps = [
  dependency('gtk4'),
  dependency('libadwaita-1', version: '>= 1.4'),
  dependency('alsa'),
  dependency('gmodule-export-2.0'),
]

ks37_sources += gnome.compile_resources('ks37-resources',
  'ks37.gresource.xml',
  c_name: 'ks37'
)

executable('keystep37-settings', ks37_sources,
  dependencies: ks37_deps,
       install: true,
)
