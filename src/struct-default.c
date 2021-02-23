#include <stdio.h> // printf

struct record {
  int value;
} record;

static const struct record global_default_record = {42};

static void safe_show(const struct record *r) {
  if (r) printf("value = %d\n", r->value);
}

static void global_default_show(const struct record *r) {
  if (!r) r = &global_default_record;
  printf("value = %d\n", r->value);
}

static void local_default_show(const struct record *r) {
  const struct record local_default_record = {42};
  if (!r) r = &local_default_record;
  printf("value = %d\n", r->value);
}

static void static_local_default_show(const struct record *r) {
  static const struct record static_default_record = {42};
  if (!r) r = &static_default_record;
  printf("value = %d\n", r->value);
}

int main() {
  safe_show(NULL);
  global_default_show(NULL);
  local_default_show(NULL);
  static_local_default_show(NULL);
}
