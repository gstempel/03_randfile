#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

unsigned* ranGen() { //get rand nums from /dev/random
  int data = open("/dev/random", O_RDONLY);
  printf("opening works\n");
  unsigned *ret;
  read(data, ret, 4);
  printf("%u\n", *ret);
  printf("reading works\n");
  close(data);
  printf("closing works\n");
  return ret;
}

int main() {
  //1: CREATE ARRAY OF RAND NUMS
  umask(0);
  int size = 3; //edit for entropy/testing purposes
  unsigned* foo[size];
  printf("Generating random numbers: \n");
  int i;
  for(i = 0; i < size; i++) {
    foo[i] = ranGen();
    printf("\nGetting for loop\n");
    printf("random %d: %d\n", i, foo[i]);
  }

  //STEP 2: WRITE THIS ARRAY OF RAND NUMS TO FILE
  int intermed = open("intermed.txt",O_WRONLY | O_CREAT, 0666);
  printf("foo[0]: %d\n",foo[0]);
  write(intermed, foo[0], 4); //okay this is writin but how write actual num?

  //STEP 3:
  return 0;
}
