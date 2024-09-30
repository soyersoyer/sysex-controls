# SysEx Controls for Linux

<img align='left' height='80' src='https://github.com/soyersoyer/sysex-controls/raw/main/data/icons/hicolor/scalable/apps/hu.irl.sysex-controls.svg'>

This is a GTK UI that allows to configure the Arturia KeyStep 37 MIDI and Arturia MiniLab MkII keyboards.

It currently allows for reading the controls, changing them and writing
back to the device.

## Installation

### From Flathub (not yet, under [review](https://github.com/flathub/flathub/pull/5635))

```
flatpak install flathub hu.irl.sysex-controls
```

### From source

```
meson setup builddir
meson compile -C builddir
meson install -C builddir
```
The resulting binary doesn't need to be installed, `./builddir/src/sysex-controls` works also.

<div>
<img alt="SysEX Controls KeyStep37 Controller page" src="https://github.com/soyersoyer/sysex-controls/raw/main/data/screenshots/page_1.png" width="410">
<img alt="SysEX Controls KeyStep37 Sequence page" src="https://github.com/soyersoyer/sysex-controls/raw/main/data/screenshots/page_2.png" width="410">
<img alt="SysEX Controls KeyStep37 CV/Gate page" src="https://github.com/soyersoyer/sysex-controls/raw/main/data/screenshots/page_3.png" width="410">
<img alt="SysEX Controls KeyStep37 Transport page" src="https://github.com/soyersoyer/sysex-controls/raw/main/data/screenshots/page_4.png" width="410">
<img alt="SysEX Controls KeyStep37 CC Bank 1 page" src="https://github.com/soyersoyer/sysex-controls/raw/main/data/screenshots/page_5.png" width="410">
</div>
