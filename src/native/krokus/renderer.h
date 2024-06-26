#ifndef RENDERER_H
#define RENDERER_H

#include <simple_renderer.h>

#include "std.h"
#include "util.h"

#define TRENDERER _ABSTRACT(krokus_renderer)

typedef struct {
  sr_Renderer renderer;
  sr_Vec4 colour;
  sr_Vec4 uv;
} Renderer;

HL_PRIM Renderer* HL_NAME(renderer_create_native) (S32 width, S32 height);
HL_PRIM U0 HL_NAME(renderer_dispose_native) (Renderer* render);
HL_PRIM U0 HL_NAME(renderer_clear_native) (Renderer* render);
HL_PRIM U0 HL_NAME(renderer_set_clear_color_native) (F32 r, F32 g, F32 b);

HL_PRIM U0 HL_NAME(renderer_push_rect_native) (
  Renderer* renderer,
  F32 x0, F32 y0,
  F32 x1, F32 y1,
  S32 texture
);

HL_PRIM U0 HL_NAME(renderer_begin_native) (Renderer* renderer);
HL_PRIM U0 HL_NAME(renderer_end_native) (Renderer* renderer);

#endif // RENDERER_H

