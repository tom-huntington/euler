{pkgs ? import <nixpkgs> {}} : #{ lib, stdenv, fetchFromGitHub, cmake, pkgs }:

pkgs.llvmPackages_12.libcxxStdenv.mkDerivation rec {
  pname = "cppcoro";
  #version = "0.11.0";
  name = "cppcoro";

  src = pkgs.fetchFromGitHub {
    owner = "lewissbaker";
    repo = "cppcoro";
    rev = "HEAD";
    sha256 = "CEdr7BTz6uVGbbsa+0pkOfJoh5T8Sln5m0IbWwf905o=";
    fetchSubmodules = true;
  };

  #patches = [
  #  source init.sh #./gcc10.patch
  #];

  nativeBuildInputs = with pkgs; [ cmake  python2Full];# boost175 ];#clang lld libcxx

  #phases = [ "unpackPhase" "buildPhase" ];

  #unpackPhase = ''
  #  echo ${src}
  #  echo ls -a ------------
  #  ls
  #  echo pwd ----------------
  #  pwd
#
  #'';
  #patchPhase = ''
  #  echo ls -a ------------
  #  ls
  #  echo pwd ----------------
  #  pwd
#
  #'';
#
  configurePhase = ''
    echo ls ------------
    ls
    echo pwd ----------------
    pwd
    source init.sh
  '';
#        export NIX_CXXSTDLIB_COMPILE=${pkgs.libcxx.dev}/include

  buildPhase = ''
        echo NIX_CXXSTDLIB_COMPILE $NIX_CXXSTDLIB_COMPILE
        echo custom install script
        echo -------------------------------------
        ls include
        ls lib
        echo PATH $PATH
        
        cake lib/build.cake --clang-executable=${pkgs.clang}/bin/clang --clang-install-prefix=/nix/store/v8imx1nvyz0hgvx9cbcmh6gp4ngw3ffj-binutils-2.35.1/ --libcxx-install-prefix=${pkgs.libcxx.dev} 
        echo build --------------------------
        ls -R build
        echo pwd
        pwd
      '';
        #--llvm-ar-executable=/nix/store/v8imx1nvyz0hgvx9cbcmh6gp4ngw3ffj-binutils-2.35.1/bin/ar
  installPhase = ''
    echo installPhase ------------------------
    ls
    mkdir $out
    echo $out

    cp -r include/ $out
    cp -r build/linux_x64_clang7.1.0_debug/lib $out/
    echo "ls out------------"
    ls -R $out
  '';
    #mkdir $out/include
    #mkdir ${out}/include
    #mkdir ${out}/lib
#
  # Building the tests currently fails on AArch64 due to internal compiler
  # errors (with GCC 9.2):
  #cmakeFlags = lib.optional stdenv.isAarch64 "-DRANGE_V3_TESTS=OFF";

  #doCheck = !stdenv.isAarch64;
  #checkTarget = "test";

  #meta = with lib; {
  #  description = "Experimental range library for C++11/14/17";
  #  homepage = "https://github.com/ericniebler/range-v3";
  #  changelog = "https://github.com/ericniebler/range-v3/releases/tag/${version}";
  #  license = licenses.boost;
  #  platforms = platforms.all;
  #  maintainers = with maintainers; [ primeos xwvvvvwx ];
  #};
}
