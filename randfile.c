#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

unsigned* ranGen() {
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
    printf("\nGetting for loop\n");
    printf("random %d: %d\n", i, foo[i]);
  }
  int intermed = open("intermed.txt",O_RDWR | O_CREAT, 0644);
  write(intermed, foo[0], 4);
  return 0;
}
