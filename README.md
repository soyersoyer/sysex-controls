# SysEx Controls for Linux

<img align="left" height="80" src="https://github.com/soyersoyer/sysex-controls/raw/main/data/icons/hicolor/scalable/apps/hu.irl.sysex-controls.svg">

This is a Libadwaita UI that allows you to configure certain Akai and Arturia devices.
It currently allows for reading the controls (Buttons, Knobs, Pads, Keys, etc)
and changing them and writing back to the device.

This is a Linux alternative to the Midi Control Center software.

These devices are supported and tested:
- Akai MPK Mini mk3
- Arturia KeyStep 37
- Arturia MiniLab mkII
- Arturia MiniLab 3

These might also work, but have not been tested yet:
- Arturia BeatStep
- Arturia KeyLab mkII 49 / 61 / 88
- Arturia KeyLab 49 / 61 / 88 mk3
- Arturia KeyLab Essential 49 / 61 / 88
- Arturia KeyLab Essential 49 / 61 / 88 mk3
- Arturia KeyStep
- Arturia MicroLab

It doesn't support the KeyStep and BeatStep Sequencer yet.

If you think some untested devices work well, please let us know.
If not, let us know as well.

## Installation

### From Flathub

<a href="https://flathub.org/apps/details/hu.irl.sysex-controls"><img width="240" alt="Download on Flathub" src="https://flathub.org/assets/badges/flathub-badge-en.png"/></a>

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

You can uninstall the program later by running

```
sudo ninja uninstall -C builddir
```

<div>
<img alt="SysEX Controls Controller List page" src="https://github.com/soyersoyer/sysex-controls/raw/main/data/screenshots/page_0.png" width="410">
<img alt="SysEX Controls KeyStep 37 Controller page" src="https://github.com/soyersoyer/sysex-controls/raw/main/data/screenshots/page_1.png" width="410">
<img alt="SysEX Controls KeyStep 37 Sequence page" src="https://github.com/soyersoyer/sysex-controls/raw/main/data/screenshots/page_2.png" width="410">
<img alt="SysEX Controls KeyStep 37 CV/Gate page" src="https://github.com/soyersoyer/sysex-controls/raw/main/data/screenshots/page_3.png" width="410">
<img alt="SysEX Controls KeyStep 37 Transport page" src="https://github.com/soyersoyer/sysex-controls/raw/main/data/screenshots/page_4.png" width="410">
<img alt="SysEX Controls KeyStep 37 CC Bank 1 page" src="https://github.com/soyersoyer/sysex-controls/raw/main/data/screenshots/page_5.png" width="410">
<img alt="SysEX Controls MiniLab 3 Preset page" src="https://github.com/soyersoyer/sysex-controls/raw/main/data/screenshots/page_6.png" width="410">
<img alt="SysEX Controls MiniLab 3 Preset 1 Pad Bank A page" src="https://github.com/soyersoyer/sysex-controls/raw/main/data/screenshots/page_7.png" width="410">
<img alt="SysEX Controls MPK Mini mk3 Preset page" src="https://github.com/soyersoyer/sysex-controls/raw/main/data/screenshots/page_8.png" width="410">
</div>
