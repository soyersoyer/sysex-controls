{
  description = "SysEx controls for Linux - configure Akai, Arturia and Korg MIDI devices";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
  };

  outputs =
    { self, nixpkgs }:
    let
      systems = [
        "x86_64-linux"
        "aarch64-linux"
      ];
      forAllSystems = nixpkgs.lib.genAttrs systems;
    in
    {
      packages = forAllSystems (
        system:
        let
          pkgs = nixpkgs.legacyPackages.${system};
        in
        {
          default = pkgs.stdenv.mkDerivation {
            pname = "sysex-controls";
            version = self.shortRev or "dirty";

            src = self;

            nativeBuildInputs = with pkgs; [
              meson
              ninja
              pkg-config
              wrapGAppsHook4
              gettext
              desktop-file-utils
              appstream-glib
              glib
            ];

            buildInputs = with pkgs; [
              gtk4
              libadwaita
              alsa-lib
            ];

            meta = with pkgs.lib; {
              description = "SysEx controls for Linux - configure Akai, Arturia and Korg MIDI devices";
              homepage = "https://github.com/soyersoyer/sysex-controls";
              license = licenses.gpl3Only;
              mainProgram = "sysex-controls";
              platforms = platforms.linux;
            };
          };
        }
      );
    };
}
