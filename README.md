# SysEx Controls for Linux

<img align='left' height='80' src='https://github.com/soyersoyer/sysex-controls/raw/main/data/icons/hicolor/scalable/apps/hu.irl.sysex-controls.svg'>

This is a GTK UI that allows to configure the Arturia KeyStep 37, MiniLab MkII, MiniLab 3 MIDI keyboards.

It currently allows for reading the controls, changing them and writing
back to the device.

## Installation

### From Flathub

<a href='https://flathub.org/apps/details/hu.irl.sysex-controls'><img width='240' alt='Download on Flathub' src='https://flathub.org/assets/badges/flathub-badge-en.png'/></a>

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
