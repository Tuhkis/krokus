#ifndef TEXTURE_H
#define TEXTURE_H

#include <simple_renderer.h>

#include "std.h"
#include "util.h"

HL_PRIM S32 HL_NAME(texture_get_white_native) (U0);
HL_PRIM S32 HL_NAME(load_texture_native) (vbyte* path, S32 path_len);

#endif // TEXTURE_H

