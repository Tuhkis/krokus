#include "renderer.h"
#include "util.h"

HL_PRIM Renderer* HL_NAME(renderer_create_native) (S32 width, S32 height) {
  Renderer* ret = malloc(sizeof(Renderer));
  
  ret->renderer = (sr_Renderer) default_initialiser;
  sr_init(&ret->renderer, width, height);

  glClearColor(.2f, .2f, .2f, 1.f);
  
  return ret;
}

HL_PRIM U0 HL_NAME(renderer_dispose_native) (Renderer* render) {
  sr_free(&render->renderer);
  free(render);
}

HL_PRIM U0 HL_NAME(renderer_clear_native) (Renderer* render) {
  glClear(GL_COLOR_BUFFER_BIT);
}

HL_PRIM U0 HL_NAME(renderer_set_clear_color_native) (F32 r, F32 g, F32 b) {
  glClearColor(r, g, b, 1.f);
}

HL_PRIM U0 HL_NAME(renderer_push_triangle_native) (
  Renderer* renderer,
  F32 x0, F32 y0,
  F32 x2, F32 y1,
  F32 x1, F32 y2,
  F32 uv0x, F32 uv0y,
  F32 uv1x, F32 uv1y,
  F32 uv2x, F32 uv2y,
  F32 r0, F32 g0, F32 b0, F32 a0,
  F32 r1, F32 g1, F32 b1, F32 a1,
  F32 r2, F32 g2, F32 b2, F32 a2,
  S32 texture
) {
  sr_render_push_triangle(&renderer->renderer, sr_vec2(x0, y0), sr_vec2(x1, y1), sr_vec2(x2, y2),
    sr_vec4(r0, g0, b0, a0), sr_vec4(r1, g1, b1, a1), sr_vec4(r2, g2, b2, a2),
    sr_vec2(uv0x, uv0y), sr_vec2(uv1x, uv1y), sr_vec2(uv2x, uv2y), texture);
}

HL_PRIM U0 HL_NAME(renderer_begin_native) (Renderer* renderer) {
  sr_render_begin(&renderer->renderer);
}

HL_PRIM U0 HL_NAME(renderer_end_native) (Renderer* renderer) {
  sr_render_end(&renderer->renderer);
}

DEFINE_PRIM(TRENDERER, renderer_create_native, _I32 _I32)
DEFINE_PRIM(_VOID, renderer_dispose_native, TRENDERER)
DEFINE_PRIM(_VOID, renderer_clear_native, TRENDERER)
DEFINE_PRIM(_VOID, renderer_set_clear_color_native, _F32 _F32 _F32)
DEFINE_PRIM(_VOID, renderer_push_triangle_native,
  TRENDERER
  _F32 _F32
  _F32 _F32
  _F32 _F32
  _F32 _F32
  _F32 _F32
  _F32 _F32
  _F32 _F32 _F32 _F32
  _F32 _F32 _F32 _F32
  _F32 _F32 _F32 _F32
  _I32
)
DEFINE_PRIM(_VOID, renderer_begin_native, TRENDERER)
DEFINE_PRIM(_VOID, renderer_end_native, TRENDERER)

