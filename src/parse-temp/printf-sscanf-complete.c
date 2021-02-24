#include <stdio.h> // printf sscanf
#include <stdlib.h> // free

int main(int argc, char**argv)
{
  if (argc != 2)
    return 1;
  const char *c = argv[1];
  while (*c && (*c != '"'))
    c++;

  char *place = NULL;
  int temperature = -300;
  if (sscanf(c, "\"%m[^,:]:%d", &place, &temperature) == 2) {
    printf("%s\n%i\n", place, temperature);
  } else {
    if (place) {
      free(place);
      place = NULL;
    }
    if (sscanf(c, "\"%m[^,:],%*[^:]:%d", &place, &temperature) == 2) {
      printf("%s\n%i\n", place, temperature);
    }
  }
  if (place) {
    free(place);
    place = NULL;
  }
  return 0;
}
