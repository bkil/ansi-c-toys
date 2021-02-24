#include <stdio.h> // printf STDOUT_FILENO
#include <stdlib.h> // atoi
#include <unistd.h> // write
#include <stdbool.h> // bool true false
#include <regex.h> // regcomp regexec regfree regex_t regmatch_t

typedef void (*with_place_temp_fn)(const char*, size_t, int);

static bool parse(const char *c, with_place_temp_fn fun) {
  regex_t preg;
  if (regcomp(&preg, "^[^\"]*\"([^,:]*)(,[^:]*)?:([+-]?[0-9]+)", REG_EXTENDED))
    return false;
  regmatch_t pmatch[4];
  int missing = regexec(&preg, c, 4, pmatch, 0);
  regfree(&preg);
  if (missing)
    return false;
  (*fun)(c + pmatch[1].rm_so, pmatch[1].rm_eo - pmatch[1].rm_so, atoi(c + pmatch[3].rm_so));
  return true;
}

static void process_place_temp(const char *place, size_t place_len, int temperature) {
  write(STDOUT_FILENO, place, place_len);
  printf("\n%d\n", temperature);
}

int main(int argc, char **argv)
{
  return (argc == 2) && parse(argv[1], &process_place_temp) ? 0 : 1;
}
