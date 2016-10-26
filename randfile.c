#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int ranGen() {
  int data = open("/dev/random", O_RDONLY);
  printf("opening works\n");
  unsigned *ret;
  read(data, ret, 4);
  printf("%u\n", *ret);
  printf("reading works\n");
  close(data);
  printf("closing works\n");
  return *ret;
}

int main() {
  int foo[10];
  printf("Generating random numbers: \n");
  int i;
  for(i = 0; i < 10; i++) {
    foo[i] = ranGen();
    printf("Getting for loop\n");
    printf("random %d: %d", i, foo[i]);
  }

  return 1;
}
