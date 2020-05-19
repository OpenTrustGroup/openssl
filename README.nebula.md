OpenSSL in NEBULA.
=======================================

## How to get source
OpenSSL is got from “git://git.openssl.org/openssl.git”,
and branch is "OpenSSL_1_1_1-stable" which is the stable branch of version 1.1.1.
And source is put in "src" folder, some build script and documents are in this folder.

* original verison : <br>
  Commit is "c352bd07ed2ff872876534c950a6968d75ef121e" and date is "Fri Feb 15 00:03:50 2019 +0100".

## How to build

If in venus, use "fx build-openssl", or uncomment script in "full-build".
* openssl dependies zircon's libraries, so build it after zircon, but before garnet.<br>
   because "fx build" which creates the image of HEE needs shared-lib of openssl.
* Now just build openssl, not export to sdk/other apps/images.
    * If sdk needs this, should uncomment "openssl:openssl_sdk" in "//garnet/public/nebula_sdk/BUILD.gn".
    * But openssl_sdk exports only static-lib. If need shared-lib, should change it.

If want build in SDK, use below bash file in some folder.

```bash
#!/bin/bash

# TODO: SET SDK'S HOME path.
NBL_SDK=/home/luocl/test/sdk/0.10/
TOOLCHAIN=${NBL_SDK}toolchains/clang/

export CROSS_COMPILE=${TOOLCHAIN}bin/

export CC=clang
export CXX=clang++
export CFLAGS="-I${NBL_SDK}hee/trusty/include --sysroot=${NBL_SDK}hee --target=aarch64-fuchsia -no-canonical-prefixes"
export CXXFLAGS="-I${NBL_SDK}hee/trusty/include --sysroot=${NBL_SDK}hee --target=aarch64-fuchsia -no-canonical-prefixes"

export LD=clang++
export LDFLAGS="--sysroot=${NBL_SDK}hee --target=aarch64-fuchsia -Wl,--icf=all -z max-page-size=4096 \
  -L${NBL_SDK}hee/lib -lfdio -lzircon"

export AR=llvm-ar
export RANLIB=llvm-ranlib

# TODO: invoke openssl's "config" script.
../openssl/config shared -no-asm

make -j

${NBL_SDK}/toolchains/clang/bin/llvm-objcopy --strip-all-gnu libcrypto.so.1.1 libcrypto.so.1.1.strip
${NBL_SDK}/toolchains/clang/bin/llvm-objcopy --strip-all-gnu libssl.so.1.1 libssl.so.1.1.strip
```

## What was changed ?

1. Add a BUILD.gn
2. Add this README.nebula.md.
