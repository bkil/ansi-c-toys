#include <stdio.h> // printf scanf
#include <limits.h> // CHAR_BIT

int eq1(int x, int y) {
  int d = x - y;
  return (1 - d*d) / (1 + d*d);
}

int eq2(int x, int y) {
  int d = x ^ y;
  return (unsigned)(d | -d) >> (sizeof(int)*CHAR_BIT-1) ^ 1;
}

int main() {
  int a, b;
  char c;
  printf("enter 2 integers and an operand (+, - or *), space separated: ");
  scanf("%d %d %c", &a, &b, &c);
  printf("%d %c %d = \n", a, c, b);

  printf("ternary: %d\n",
    c=='-' ? a-b : c=='+' ? a+b : a*b);

// https://en.wikipedia.org/wiki/Boolean_data_type#C,_C++,_Objective-C,_AWK
  printf("boolean: %d\n",
    (c=='-') * (a-b) + (c=='+') * (a+b) + (c=='*') * a*b);

  printf("algebraic %d\n",
    eq1(c, '-') * (a-b) + eq1(c, '+') * (a+b) + eq1(c, '*') * a*b);

  printf("bitwise: %d\n",
    eq2(c, '-') * (a-b) + eq2(c, '+') * (a+b) + eq2(c, '*') * a*b);

// * 42
// + 43
// - 45
  printf("ASCII: %d\n",
    c/45 * (a-b) +
    (1 - c/45 - (45-c)/3) * (a+b) +
    (45-c)/3 * a*b);
}
