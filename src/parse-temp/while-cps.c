#include <stdio.h> // printf STDOUT_FILENO
#include <stdlib.h> // atoi
#include <unistd.h> // write
#include <stdbool.h> // bool true false

typedef void (*with_place_temp_fn)(const char *, size_t, int);

bool parse(const char *c, with_place_temp_fn fun) {
  while (*c && (*c++ != '"'));
  const char *place = c;
  while (*c && (*c != ',') && (*c != ':'))
    c++;
  size_t place_len = c - place;
  while (*c && (*c++ != ':'));
  if (!*c)
    return false;
  int temperature = atoi(c);
  (*fun)(place, place_len, temperature);
  return true;
}

void process_place_temp(const char *place, size_t place_len, int temperature) {
  write(STDOUT_FILENO, place, place_len);
  printf("\n%d\n", temperature);
}

int main(int argc, char**argv)
{
  return (argc == 2) && parse(argv[1], &process_place_temp) ? 0 : 1;
}
