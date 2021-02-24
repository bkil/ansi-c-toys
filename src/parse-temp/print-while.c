#include <stdio.h> // putchar

int main(int argc, char**argv)
{
  if (argc != 2)
    return 1;
  char *c = argv[1];
  while (*c && (*c++ != '"'));
  while (*c && (*c != ',') && (*c != ':'))
    putchar(*c++);
  putchar(10);
  while (*c && (*c++ != ':'));
  while (*c && ((*c >= '0') && (*c <= '9') || (*c == '+') || (*c == '-')))
    putchar(*c++);
  putchar(10);
  return 0;
}
