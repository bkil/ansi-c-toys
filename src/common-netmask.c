#include <stdio.h>
#include <stdbool.h>

#define uint32 unsigned int
#define BROADCAST 0xffffffff
#define IP(a,b,c,d) ((a)<<24 | (b)<<16 | (c)<<8 | (d))

uint32 get_lowest_one(uint32 x) {
  return x & -x;
}

bool is_power_of_two(uint32 x) {
  return x == get_lowest_one(x);
}

uint32 clear_lowest_one(uint32 x) {
  return x ^ get_lowest_one(x);
}

uint32 keep_top_ones(uint32 x) {
  while (!is_power_of_two(-x)) {
    x = clear_lowest_one(x);
  }
  return x;
}

uint32 equal_bits(uint32 a, uint32 b) {
  return a ^ ~b;
}

uint32 common_netmask_2(uint32 netmask, uint32 ip1, uint32 ip2) {
  return keep_top_ones(netmask & equal_bits(ip1, ip2));
}

uint32 common_netmask(uint32 ip[]) {
  uint32 netmask = BROADCAST;
  uint32 base = ip[0];
  if (base == BROADCAST)
    return netmask;

  for (size_t i = 1; ip[i] != BROADCAST; i++) {
    netmask = common_netmask_2(netmask, base, ip[i]);
  }
  return netmask;
}

int main() {
  uint32 ip[] = {
    IP(192,168,1,10),
    IP(192,168,2,10),
    IP(192,169,254,1),
    BROADCAST
  };

  uint32 netmask = common_netmask(ip);
  printf("%08x/%08x\n", ip[0] & netmask, netmask);
}
