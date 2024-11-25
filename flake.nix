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

              # Haskell bin (executables)
              # Avoid haskellPackages.fooXYZ as they may disppear (dropped), see:
              # https://nixos.org/manual/nixpkgs/unstable/#haskell-available-packages
              # Let ghc know where to find these libs, see:
              # #how-to-create-a-development-environment in hask4nix.readthedocs.io
              # hkgs
              (pkgs.haskellPackages.ghcWithPackages (p: with p; [
                hlint           # 3.5
                hindent         # 6.0.0

                # tools
                cabal-install
                pandoc
              ]))

              haskellPackages.ghcid   # 0.8.9
              # haskellPackages.ghc     # 9.4.6 (LTS Stackage)
              haskellPackages.stack   # 2.11.1
              haskellPackages.haskell-language-server # support only GHC version of this flake
              # Ocaml
              ocamlPackages.ocaml
              ocamlPackages.dune_3
              ocamlPackages.findlib
              ocamlPackages.utop
              ocamlPackages.odoc
              ocamlPackages.ocaml-lsp
              ocamlformat

              # C/CPP
              pkg-config
              ccls
              # vcpkg

              # Debugging
              gdb
              valgrind          # 3.21

              # Java and JVM langs such as clojure
              jdk17_headless
              clojure
              clojure-lsp

              # Scheme
              guile
              chicken
              chickenPackages_5.chickenEggs.tree

              # JavaScript
              nodejs_20

              # Auto tools
              just

            ];
          };


        }
    );

  # Optional
  # See `flake-format` section of nix flake in Nix Reference Manual
  nixConfig = {
    bash-prompt = "[\\[\\e[38;5;39m\\]\\w\\[\\e[0m\\] λ] ";
  };
}
