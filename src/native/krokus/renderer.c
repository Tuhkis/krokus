#include "renderer.h"
#include "util.h"

HL_PRIM Renderer* HL_NAME(renderer_create_native) (S32 width, S32 height) {
  Renderer* ret = malloc(sizeof(Renderer));
  
  ret->renderer = (sr_Renderer) default_initialiser;
  sr_init(&ret->renderer, width, height);
  
  return ret;
}

HL_PRIM void HL_NAME(renderer_dispose_native) (Renderer* render) {
  sr_free(&render->renderer);
  free(render);
}

DEFINE_PRIM(TRENDERER, renderer_create_native, _I32 _I32)
DEFINE_PRIM(_VOID, renderer_dispose_native, TRENDERER)

