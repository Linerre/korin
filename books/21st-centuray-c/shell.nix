{ pkgs ?
  import (fetchTarball "https://github.com/NixOS/nixpkgs/archive/d4abba5c1e8dfb3d2d88160a42071070537412be.tar.gz") {} }:

pkgs.mkShell rec {
  # run-time deps
  buildInputs = with pkgs; [
    # Compiling and debugging
    gcc
    gdb
    valgrind
    gnumake
    binutils                    # provide `gprof'
    pkg-config
    doxygen

    # For libraries
    curl                        # provide `libcurl' + `libgsl'
    sqlite                      # provide `libsqlite3'
    libxml2                     # provide `libxml2'

    # Autotools
    autoconf
    automake
    libtool
    git
    zsh
  ];

  # Set up bash
  shellHook = ''
    PS1="\n\[\033[1;32m\][nix:\W]\$\[\033[0m\] "
    alias c99="gcc --std=gnu99"
    alias e="emacs -nw"
    alias mg="mg -n"
  '';
}
