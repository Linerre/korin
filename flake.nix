# Top-level flake for all (including the current) my projects
# Other flakes should `follows` this one to share the buildInputs
{
  # Optional
  description = "A messy envrionment that ONLY Nix can handle for my personal learning.";

  # Optional
  inputs = {
    flake-utils.url = "github:numtide/flake-utils";
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
    rust-overlay.url = "github:oxalica/rust-overlay";
  };

  # Required
  outputs = { self, flake-utils, nixpkgs, rust-overlay }:
    # Target only AMD64 Linux, references:
    # 1. https://github.com/numtide/flake-utils#eachsystem--system---system---attrs
    # 2. https://yuanwang.ca/posts/getting-started-with-flakes.html (flake-utils sections)
    # If using `lib.eachDefaultSystem', refer to
    # https://github.com/numtide/flake-utils#defaultsystems--system
    flake-utils.lib.eachSystem [ "x86_64-linux" ] (system:
      let
        overlays = [ (import rust-overlay) ];
        pkgs = import nixpkgs { inherit system overlays; };
      in
        # Attr set to be outputed by this flake
        {
          devShells.default = pkgs.mkShell {

            shellHook = ''
              alias e="emacs -nw"
              alias ll="ls -al"
            '';

            # Packages needed at runtime
            # Consider them as global pkgs avail. in devenv's $PATH
            buildInputs = with pkgs; [
              # Rust
              (rust-bin.stable.latest.default.override {
                extensions = [ "rust-src" ];
              })
              cargo
              rust-analyzer

              # Haskell
              # Avoid haskellPackages.foo_x_y_z as they may disppear (dropped), see:
              # https://nixos.org/manual/nixpkgs/unstable/#haskell-available-packages
              haskellPackages.ghc     # 9.4.6 (LTS Stackage)
              haskellPackages.ghcid   # 0.8.9
              haskellPackages.hlint   # 3.5
              haskellPackages.hindent # 6.0.0

              # Ocaml

              # C
              pkg-config

              # CPP

              # Debugging
              gdb
              valgrind          # 3.21
            ];
          };


        }
    );

  # Optional
  # See `flake-format` section of nix flake in Nix Reference Manual
  nixConfig = {
    bash-prompt = "[λ] ";
  };
}
