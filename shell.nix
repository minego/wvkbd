{ pkgs ? import <nixpkgs> { } }:

pkgs.mkShell {
	name				= "wvkbd dev shell";

	nativeBuildInputs = with pkgs; [
		pkg-config
		wayland-scanner
	];

	buildInputs = with pkgs; [
		cairo
		glib
		harfbuzz
		libxkbcommon
		pango
		wayland
	];
}
