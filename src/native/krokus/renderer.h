#ifndef RENDERER_H
#define RENDERER_H

#include <simple_renderer.h>

#include "std.h"
#include "util.h"

#define TRENDERER _ABSTRACT(krokus_renderer)

typedef struct {
  sr_Renderer renderer;
} Renderer;

HL_PRIM Renderer* HL_NAME(renderer_create_native) (S32 width, S32 height);
HL_PRIM void HL_NAME(renderer_dispose_native) (Renderer* render);

#endif // RENDERER_H

