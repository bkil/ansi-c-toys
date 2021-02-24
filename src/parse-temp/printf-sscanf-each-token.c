#include <stdio.h> // printf sscanf
#include <stdlib.h> // free

int main(int argc, char**argv)
{
  if (argc != 2)
    return 1;
  const char *c = argv[1];
  int ofs = 0;
  sscanf(c, "%*[^\"]%n", &ofs);
  c += ofs;
  char *place = NULL;
  if (sscanf(c, "\"%m[^,:]%n", &place, &ofs) != 1)
    return 1;
  c += ofs;
  ofs = 0;
  sscanf(c, ",%*[^:]%n", &ofs);
  c += ofs;
  int temperature;
  if (sscanf(c, ":%d", &temperature) != 1) {
    free(place);
    return 1;
  }
  printf("%s\n%i\n", place, temperature);
  free(place);
  return 0;
}
