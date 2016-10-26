#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

unsigned ranGen() { //get rand nums from /dev/random
  int data = open("/dev/random", O_RDONLY);
  unsigned ret;
  read(data, &ret, 4);
  //printf("%u\n", ret);
  close(data);
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
    printf("random %d: %u\n", i, foo[i]);
  }

  //STEP 2: WRITE THIS ARRAY OF RAND NUMS TO FILE
  printf("Writing numbers to file...\n");
  int intermed = open("intermed.txt",O_WRONLY | O_CREAT, 0666);
  //printf("foo[0]: %d\n",foo[0]);
  write(intermed, foo, 4*size); //okay this is writin but how write actual num?
  unsigned* boo[size];
  printf("Reading numbers from file...\n");
  read(intermed, boo, 4*size);
  for(i=0; i < size; i++) {
    printf("random %d: %u\n", i, boo[i]);
  }

  //STEP 3:
  return 0;
}
