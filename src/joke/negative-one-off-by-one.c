#include <stdio.h>

/*
> - `-3^3` says to `-3|3`: _"I see you're the negative one"_
> - That one replies: _"You're off by one"_
*/

int main() {
  printf("-2: %d %x ; -1: %d %x\n", -3^3, -3^3, -3|3, -3|3);
}
