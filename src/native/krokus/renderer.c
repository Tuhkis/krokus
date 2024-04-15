#include "renderer.h"
#include "util.h"

HL_PRIM Renderer* HL_NAME(renderer_create_native) (S32 width, S32 height) {
  Renderer* ret = malloc(sizeof(Renderer));

  ret->renderer = (sr_Renderer) default_initialiser;
  sr_init(&ret->renderer, width, height);
  ret->colour = sr_vec4(1, 1, 1, 1);
  ret->uv = sr_vec4(0, 0, 1, 1);

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
  S32 texture
) {
  // sr_render_push_quad(&renderer->renderer, sr_vec2(x0, y0), sr_vec2(x1, y1), renderer->colour, texture);

  sr_render_push_triangle(
    &renderer->renderer,
    sr_vec2(x0, y0),
    sr_vec2(x0 + x1, y0), sr_vec2(x0, y0 + y1),
    renderer->colour,
    renderer->colour,
    renderer->colour,
    sr_vec2(renderer->uv.x, renderer->uv.y),
    sr_vec2(renderer->uv.z, renderer->uv.y),
    sr_vec2(renderer->uv.x, renderer->uv.w), texture);

  sr_render_push_triangle(&renderer->renderer,
    sr_vec2(x0 + x1, y0 + y1),
    sr_vec2(x0 + x1, y0),
    sr_vec2(x0, y0 + y1),
    renderer->colour, renderer->colour, renderer->colour,
    sr_vec2(renderer->uv.z, renderer->uv.w),
    sr_vec2(renderer->uv.z, renderer->uv.y),
    sr_vec2(renderer->uv.x, renderer->uv.w), texture);
}

HL_PRIM U0 HL_NAME(renderer_begin_native) (Renderer* renderer) {
  sr_render_begin(&renderer->renderer);
}

HL_PRIM U0 HL_NAME(renderer_end_native) (Renderer* renderer) {
  sr_render_end(&renderer->renderer);
}

HL_PRIM U0 HL_NAME(renderer_set_color_native) (Renderer* renderer, F32 r, F32 g, F32 b, F32 a) {
  renderer->colour = sr_vec4(r, g, b, a);
}

DEFINE_PRIM(TRENDERER, renderer_create_native, _I32 _I32)
DEFINE_PRIM(_VOID, renderer_dispose_native, TRENDERER)
DEFINE_PRIM(_VOID, renderer_clear_native, TRENDERER)
DEFINE_PRIM(_VOID, renderer_set_clear_color_native, _F32 _F32 _F32)
DEFINE_PRIM(_VOID, renderer_push_rect_native,
  TRENDERER
  _F32 _F32
  _F32 _F32
  _I32
)
DEFINE_PRIM(_VOID, renderer_begin_native, TRENDERER)
DEFINE_PRIM(_VOID, renderer_end_native, TRENDERER)
DEFINE_PRIM(_VOID, renderer_set_color_native, TRENDERER _F32 _F32 _F32 _F32)

