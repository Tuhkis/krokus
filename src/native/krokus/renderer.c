#include "renderer.h"
#include "util.h"

HL_PRIM Renderer* HL_NAME(renderer_create_native) (S32 width, S32 height) {
  Renderer* ret = malloc(sizeof(Renderer));
  
  ret->renderer = (sr_Renderer) default_initialiser;
  sr_init(&ret->renderer, width, height);

  glClearColor(.2f, .2f, .2f, 1.f);
  
  return ret;
}

HL_PRIM void HL_NAME(renderer_dispose_native) (Renderer* render) {
  sr_free(&render->renderer);
  free(render);
}

HL_PRIM void HL_NAME(renderer_clear_native) (Renderer* render) {
  glClear(GL_COLOR_BUFFER_BIT);
}

DEFINE_PRIM(TRENDERER, renderer_create_native, _I32 _I32)
DEFINE_PRIM(_VOID, renderer_dispose_native, TRENDERER)
DEFINE_PRIM(_VOID, renderer_clear_native, TRENDERER)

