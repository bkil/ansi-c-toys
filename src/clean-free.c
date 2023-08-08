#include <stdio.h> // printf
#include "clean-free.h" // freep

int
main(void) {
  freep((int **)0);

  int *n = NULL;
  freep(&n);
  printf("%p\n", (void *)n);

  struct { int i; } *s = malloc(sizeof(*s));
  freep(&s);
  printf("%p\n", (void *)s);

// Will produce compile error:
//  free(n);
//  freep(n);
  return 0;
}
