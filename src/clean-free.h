#ifndef _clean_free_h
#define _clean_free_h

#include <stdlib.h> // free NULL

static void (*__clean_free_stdlib_free)(void *) = free;

#define free(x) /"use freep() instead"

#define freep(p) \
  do { \
    if ((void *)p != NULL) { \
      (*__clean_free_stdlib_free)(*p); \
      *p = NULL; \
    } \
  } while (0)

#endif
