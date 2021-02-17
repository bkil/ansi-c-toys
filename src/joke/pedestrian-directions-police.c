/*
> - Why didn't the `void (*pedestrian)(char)` get **directions** from `"police"`?
> - Because it can't be given **pointers**
*/

void pedestrian(char directions) {}

int main() {
  pedestrian("police");
}
