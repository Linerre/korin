# A simple flake without flake-util
# From: https://nix-tutorial.gitlabpages.inria.fr/nix-tutorial/flakes.html
{
  description = "A very basic flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/22.05";
  };

  outputs = { self, nixpkgs }:
    let
      system = "x86_64-linux";
      # inherit ``copies'' the above ``system'', so it's equivalent to say
      # import nixpkgs { system = system; }
      # See: https://nixos.org/manual/nix/stable/language/constructs#inheriting-attributes
      pkgs = import nixpkgs { inherit system; };
    in {
      # First, the type of outputs (packages, devShells, checks ...)
      packages.${system} = rec {
        chord = pkgs.callPackage ./pkgs/chord {};
        chord_custom_sg = pkgs.callPackage ./pkgs/chord { simgrid = custom_simgrid; };
        custom_simgrid = pkgs.callPackage ./pkgs/simgrid/custom.nix {};
      };

      # Second, the target architecture (x86_64-linux, aarch64-linux, x86_64-darwin ...)

      # Last, the name of the output
    };
}
