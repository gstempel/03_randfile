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
  int size = 10; //edit for entropy/testing purposes
  unsigned foo[size];
  printf("\nGenerating random numbers: \n");
  int i;
  for(i = 0; i < size; i++) {
    foo[i] = ranGen();
    printf("random %d: %u\n", i, foo[i]);
  }

  //STEP 2: WRITE THIS ARRAY OF RAND NUMS TO FILE
  printf("\nWriting numbers to file...\n");
  int intermed = open("intermed.txt",O_WRONLY | O_CREAT, 0666);
  write(intermed, foo, 4*size); //okay this is writin but how write actual num?
  intermed = close(intermed);
  intermed = open("intermed.txt", O_RDONLY, 0666);
  unsigned boo[size];
  printf("\nReading numbers from file...\nVerification: \n");
  read(intermed, boo, 4*size);
  for(i=0; i < size; i++) {
    printf("random %d: %u\n", i, boo[i]);
  }

  //STEP 3:
  return 0;
}
