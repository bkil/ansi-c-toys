#include <stdio.h> // printf
#include <stdbool.h> // bool
#include <stdint.h> // uint32_t

#define BROADCAST 0xffffffff
#define IP(a,b,c,d) ((a)<<24 | (b)<<16 | (c)<<8 | (d))

uint32_t get_lowest_one(uint32_t x) {
  return x & -x;
}

bool is_power_of_two(uint32_t x) {
  return x == get_lowest_one(x);
}

uint32_t clear_lowest_one(uint32_t x) {
  return x ^ get_lowest_one(x);
}

uint32_t keep_top_ones(uint32_t x) {
  while (!is_power_of_two(-x)) {
    x = clear_lowest_one(x);
  }
  return x;
}

uint32_t equal_bits(uint32_t a, uint32_t b) {
  return a ^ ~b;
}

uint32_t common_netmask_2(uint32_t netmask, uint32_t ip1, uint32_t ip2) {
  return keep_top_ones(netmask & equal_bits(ip1, ip2));
}

uint32_t common_netmask(uint32_t ip[]) {
  uint32_t netmask = BROADCAST;
  uint32_t base = ip[0];
  if (base == BROADCAST)
    return netmask;

  for (size_t i = 1; ip[i] != BROADCAST; i++) {
    netmask = common_netmask_2(netmask, base, ip[i]);
  }
  return netmask;
}

int main() {
  uint32_t ip[] = {
    IP(192,168,1,10),
    IP(192,168,2,10),
    IP(192,169,254,1),
    BROADCAST
  };

  uint32_t netmask = common_netmask(ip);
  printf("%08x/%08x\n", ip[0] & netmask, netmask);
}
