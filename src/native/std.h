#ifndef STD_H
#define STD_H

#include <stdlib.h>

// This isn't part of the standard library...
#define HL_NAME(n) krokus_##n
#include "hl.h"

// Linux specific headers.
#ifdef OS_LINUX
#include <time.h>
#include <errno.h>
#endif // OS_LINUX

// Windows specific header.
#ifdef OS_WINDOWS
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif // OS_WINDOWS

#endif // STD_H

