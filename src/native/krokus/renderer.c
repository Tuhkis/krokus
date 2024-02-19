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

HL_PRIM U0 HL_NAME(renderer_push_rect_native) (
  Renderer* renderer,
  F32 x0, F32 y0,
  F32 x1, F32 y1,
  F32 r, F32 g, F32 b, F32 a,
  S32 texture
) {
  sr_Vec4 col = sr_vec4(r, g, b, a);
  sr_render_push_quad(&renderer->renderer, sr_vec2(x0, y0), sr_vec2(x1, y1), col, texture);
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
DEFINE_PRIM(_VOID, renderer_push_rect_native,
  TRENDERER
  _F32 _F32
  _F32 _F32
  _F32 _F32 _F32 _F32
  _I32
)
DEFINE_PRIM(_VOID, renderer_begin_native, TRENDERER)
DEFINE_PRIM(_VOID, renderer_end_native, TRENDERER)

