# in file ./shell.nix
{pkgs ? import <nixpkgs> {}} : 
let 
    cppcoro = import ./cppcoro.nix {};
    #clang-range-v3 = import ./clang-range-v3.nix { inherit pkgs; };
    in
pkgs.llvmPackages_12.libcxxStdenv.mkDerivation {
  name = "clang-nix-shell";
  nativeBuildInputs = with pkgs; [ cmake ninja];
  buildInputs = with pkgs; [ cppcoro range-v3 boost175];# llvmPackages_12.libcxx.dev llvmPackages_12.libcxx/* add libraries here */ ];
      #exprot NIX_CXXSTDLIB_COMPILE=${pkgs.libcxx.dev}/include
      #export NIX_TARGET_CXXSTDLIB_COMPILE=${llvmPackages_13.libcxx.dev}/include
      #echo NIX_TARGET_CXXSTDLIB_COMPILE $NIX_TARGET_CXXSTDLIB_COMPILE
      #export NIX_CXXSTDLIB_COMPILE=${llvmPackages_13.libcxx.dev}/include
      #echo NIX_CXXSTDLIB_COMPILE $NIX_CXXSTDLIB_COMPILE
      #export libcpp_includes="${llvmPackages_13.libcxx}/include/c++/v1"
      #export NIX_CFLAGS_COMPILE="$NIX_CFLAGS_COMPILE -isystem ${llvmPackages_12.libcxx.dev}/include/c++/v1"
    #export LIBCXX_INCLUDE=${llvmPackages_12.libcxx.dev}/include/c++/v1
      #echo llvmPackages_13.libcxx ${llvmPackages_12.libcxx}
  shellHook = with pkgs; ''
      export CPPCORO_INCLUDE=${cppcoro}/include
      export CPPCORO_LIBS=${cppcoro}/lib
      export RANGE_V3_INCLUDE_DIR=${range-v3}/include
    '';
}
