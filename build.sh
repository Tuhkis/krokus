#!/bin/bash

RED="\e[31m"
GREEN="\e[32m"
YELLOW="\e[33m"
NORM="\e[0m"

CC="clang"
BUILD_MODE="-DDEBUG_BUILD"
SRC="src/native"
INC="-I./external/sr -I./external/ll -I./external/glfw-ez/glfw/include/GLFW -I./src/native -I./external -I./external/cph"
CFLAGS="-pipe -O0 -Werror -Wpedantic -Wall -std=c11 -fPIC ${INC} ${BUILD_MODE}"
LIBFLAGS="-Ofast -fPIC -mavx -maes -march=x86-64 -msse4.1"
OUT="krokus.hdll"
BIN="bin"

mkdir -p bin

function build_info () {
  echo -e "${YELLOW}[BUILD]${NORM} $1"
}

if [ "$1" = "clean" ]; then
  echo -e "${YELLOW}[CLEAN]${NORM} Removing binaries..."
  rm -rf bin
  echo -e "${YELLOW}[CLEAN]${GREEN} Done.${NORM}"
  exit 0
fi

if [ "$1" = "release" ]; then
  build_info "Building in release mode..."
  BUILD_MODE="-DRELEASE_BUILD"
  CFLAGS="-pipe -Ofast -mavx -maes -march=x86-64 -msse4.1 -Werror -Wpedantic -Wall -std=c11 -fPIC ${INC} ${BUILD_MODE}"
fi

if ! $(test -f ${BIN}/glfw-ez_impl.o); then
  build_info "Building glfw-ez.c"
  ${CC} ${LIBFLAGS} -w -Wno-error -c ./${SRC}/build/glfw-ez_impl.c -o ${BIN}/glfw-ez_impl.o
fi

if ! $(test -f ${BIN}/sr.o); then
  build_info "Building simple_renderer.c"
  ${CC} ${LIBFLAGS} -w -c ./external/sr/simple_renderer.c -o ${BIN}/sr.o
fi

if ! $(test -f ${BIN}/stb_impl.o); then
  build_info "Building stb_image.h"
  ${CC} ${LIBFLAGS} -w -c ./${SRC}/build/stb_impl.c -o ${BIN}/stb_impl.o
fi

build_info "Building the hdll..."
if ! $(${CC} ${CFLAGS} -c ${SRC}/build/unity.c -o ${BIN}/unity.o); then
  echo -e "${RED}[ERROR]${NORM} Couldn't build the shared library."
  exit 1
fi

build_info "Linking the hdll..."
if ! $(${CC} ${BIN}/*.o ${LIBS} -o ${BIN}/${OUT} -shared -lX11); then
  echo -e "${RED}[ERROR]${NORM} Couldn't link the shared library."
  exit 1
fi

build_info "${GREEN}Done.${NORM}"

