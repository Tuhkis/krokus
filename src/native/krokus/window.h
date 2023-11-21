#ifndef WINDOW_H
#define WINDOW_H

#include <glfw3.h>

#include "std.h"
#include "util.h"

#define TWINDOW _ABSTRACT(krokus_window)

typedef struct {
  GLFWwindow* win;
} Window;

HL_PRIM void HL_NAME(window_system_init_native) (void);
HL_PRIM Window* HL_NAME(window_create_native) (S32 width, S32 height, vbyte* title, int title_len);
HL_PRIM void HL_NAME(window_dispose_native) (Window* win);
HL_PRIM bool HL_NAME(window_should_close_native) (Window* win);
HL_PRIM void HL_NAME(window_poll_events_native) (void);

#endif // WINDOW_H

