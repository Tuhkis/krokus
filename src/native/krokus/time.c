#include "time.h"
#include "util.h"

// Clang will eat my internal organs if this isn't here.
#ifdef OS_LINUX
#ifndef nanosleep
extern S32 nanosleep(const struct timespec* a, struct timespec* b);
#endif // nanosleep
#endif // OS_LINUX

HL_PRIM U0 HL_NAME(delay_native) (F32 ms) {
#ifdef OS_LINUX
  if (ms < 0.f) {
    return;
  }
  mut struct timespec ts = default_initialiser;
  mut S32 res = 0;
  ts.tv_sec = ms * 0.001f;
  ts.tv_nsec = ((U64)ms % 1000) * 1000000;
  do {
    res = nanosleep(&ts, &ts);
  } while (res && errno == EINTR);
#endif // OS_LINUX
#ifdef OS_WINDOWS
  // timeBeginPeriod(1);
  Sleep((U64)ms);
  // timeEndPeriod(1);
#endif // OS_WINDOWS
}

HL_PRIM F32 HL_NAME(get_time_native) (U0) {
  return glfwGetTime();
}

DEFINE_PRIM(_VOID, delay_native, _F32)
DEFINE_PRIM(_F32, get_time_native, _NO_ARG)

