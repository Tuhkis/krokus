#include "texture.h"

HL_PRIM S32 HL_NAME(texture_get_white_native) (U0) {
  return sr_get_white_texture();
}

DEFINE_PRIM(_I32, texture_get_white_native, _NO_ARG)

