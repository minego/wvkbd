{ inputs, stdenv, lib, fetchFromGitHub, wayland-scanner, wayland, pango, glib, harfbuzz, cairo, pkg-config, libxkbcommon }:

stdenv.mkDerivation rec {
	pname				= "wvkbd-minego";
	version				= "0.14.3";

#	src = fetchFromGitHub {
#		owner			= "jjsullivan5196";
#		repo			= pname;
#		rev				= "v${version}";
#		sha256			= "sha256-U4xq9FY2uZlnBwm8Se1wReU1c1RAJMx6FIoD0D2BlM4=";
#	};
	src = ./.;

	postPatch = ''
        substituteInPlace config.mk --replace "mobintl" "minego"
        substituteInPlace Makefile --replace "pkg-config" "$PKG_CONFIG"
        '';

	nativeBuildInputs = [
		pkg-config
		wayland-scanner
	];
	buildInputs = [
		cairo
		glib
		harfbuzz
		libxkbcommon
		pango
		wayland
	];
	installFlags		= [ "PREFIX=$(out)" ];

	meta = with lib; {
		homepage		= "https://github.com/jjsullivan5196/wvkbd";
		description		= "On-screen keyboard for wlroots with my own layout";
		platforms		= platforms.linux;
		license			= licenses.gpl3Plus;
		mainProgram		= "wvkbd-minego";
	};
}
