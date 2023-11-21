#include <simple_renderer.h>

#include "hl_string.h"
#include "std.h"
#include "util.h"
#include "window.h"

HL_PRIM Window* HL_NAME(window_create_native) (S32 width, S32 height, vbyte* title, int title_len) {
  Window* ret = malloc(sizeof(Window));

  char title_buf[title_len + 1];
  title_buf[title_len] = 0;
  chars_from_vbytes(title_buf, title, title_len);

  ret->win = glfwCreateWindow(width, height, title_buf, nullptr, nullptr);
  ASSERT(ret->win != nullptr);
  glfwMakeContextCurrent(ret->win);
	glfwSwapInterval(0);
	sr_load_loader(glfwGetProcAddress);
  
  return ret;
}

HL_PRIM void HL_NAME(window_dispose_native) (Window* win) {
  glfwDestroyWindow(win->win);
  free(win);
}

HL_PRIM void HL_NAME(window_system_init_native) (void) {
  ASSERT(glfwInit() != GLFW_FALSE);
  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

HL_PRIM bool HL_NAME(window_should_close_native) (Window* win) {
  return glfwWindowShouldClose(win->win);
}

HL_PRIM void HL_NAME(window_poll_events_native) (void) {
  glfwPollEvents();
}

DEFINE_PRIM(TWINDOW, window_create_native, _I32 _I32 _BYTES _I32)
DEFINE_PRIM(_VOID, window_dispose_native, TWINDOW)
DEFINE_PRIM(_VOID, window_system_init_native, _NO_ARG)
DEFINE_PRIM(_BOOL, window_should_close_native, TWINDOW)
DEFINE_PRIM(_VOID, window_poll_events_native, _NO_ARG)

