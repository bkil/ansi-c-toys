#include <stdio.h> // printf
#include <stdlib.h> // atoi
#include <string.h> // strndup
#include <stdbool.h> // bool true false

bool parse(const char *c, char **place, int *temperature) {
  while (*c && (*c++ != '"'));
  const char *p = c;
  while (*c && (*c != ',') && (*c != ':'))
    ++c;
  size_t n = c - p;
  while (*c && (*c++ != ':'));
  if (!*c)
    return false;
  *temperature = atoi(c);
  *place = strndup(p, n);
  return true;
}

int main(int argc, char**argv)
{
  if (argc != 2)
    return 1;

  char *place;
  int temperature;
  if (!parse(argv[1], &place, &temperature))
    return 1;
  printf("%s\n%d\n", place, temperature);
  free(place);
  return 0;
}
