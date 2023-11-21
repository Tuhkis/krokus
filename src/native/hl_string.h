#ifndef HL_STRING_H
#define HL_STRING_H

#include "std.h"
#include "util.h"

static inline void chars_from_vbytes(char* dst, vbyte* str, S32 len) {
  for (int i = 0; i < len; ++i)
    dst[i] = *(str + i * 2);
}

#endif // HL_STRING_H

