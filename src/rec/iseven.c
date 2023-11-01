#include <stdio.h> /* printf */

static int
isEven(int x) {
  return x == 0 ? 1 : x == 1 ? 0 : isEven(x < 0 ? -x : x - 2);
}

int
main(int argc, char **argv)
{
  const int ins[] = {69, 42, -3, -2, -1, 1, 0};
  for (size_t i = 0; i < sizeof(ins)/sizeof(ins[0]); i++) {
    printf("isEven(%d) = %d\n", ins[i], isEven(ins[i]));
  }
}
