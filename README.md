# KeyStep37 Settings

<img align='left' height='80' src='https://github.com/soyersoyer/keystep37-settings/raw/main/data/icons/hicolor/scalable/apps/hu.irl.keystep37-settings.svg'>

This is a GTK UI that allows to configure the Arturia KeyStep 37 MIDI keyboard.

It currently allows for reading the controls, changing them and writing
back to the device.

## Installation

### From Flathub (not yet, under [review](https://github.com/flathub/flathub/pull/5635))

```
flatpak install flathub hu.irl.keystep37-settings
```

### From source

```
meson setup builddir
meson compile -C builddir
meson install -C builddir
```
The resulting binary doesn't need to be installed, `./builddir/src/keystep37-settings` works also.

<div>
<img alt="KeyStep37 Settings Controller page" src="https://github.com/soyersoyer/keystep37-settings/raw/main/data/screenshots/page_1.png" width="410">
<img alt="KeyStep37 Settings Sequence page" src="https://github.com/soyersoyer/keystep37-settings/raw/main/data/screenshots/page_2.png" width="410">
<img alt="KeyStep37 Settings CV/Gate page" src="https://github.com/soyersoyer/keystep37-settings/raw/main/data/screenshots/page_3.png" width="410">
<img alt="KeyStep37 Settings Transport page" src="https://github.com/soyersoyer/keystep37-settings/raw/main/data/screenshots/page_4.png" width="410">
<img alt="KeyStep37 Settings CC Bank 1 page" src="https://github.com/soyersoyer/keystep37-settings/raw/main/data/screenshots/page_5.png" width="410">
</div>
