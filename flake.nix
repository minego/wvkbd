{
	description = "wvkbd with my own layout";

	inputs = {
		nixpkgs = {
			url = "github:NixOS/nixpkgs/nixos-unstable";
		};

		# Override the systems for the flake, because this only builds on Linux
		systems = {
			url = "github:nix-systems/default-linux";
		};

		flake-utils = {
			url	= "github:numtide/flake-utils";
			inputs.systems.follows = "systems";
		};
	};

	outputs = { self, nixpkgs, flake-utils, ... }@inputs:

	let
		overlay = final: prev: {
			# Replace the 'wvkbd' in nixpkgs with our own
			wvkbd = prev.pkgs.callPackage ./derivation.nix { inherit inputs; };
		};
	in

	flake-utils.lib.eachDefaultSystem (system:
		let
			pkgs = nixpkgs.legacyPackages.${system}.extend overlay;
		in rec {
			packages.wvkbd			= pkgs.wvkbd;

			packages.default		= packages.wvkbd;
			devShells.default		= import ./shell.nix { inherit pkgs; };
		}
	)
	//
	{
		overlays.default			= overlay;
	};
}


