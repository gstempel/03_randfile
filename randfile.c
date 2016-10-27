#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

unsigned ranGen() { //get rand nums from /dev/random
  int data = open("/dev/random", O_RDONLY);
  if(data == -1) {printf("%s\n",strerror(errno));}

  unsigned ret;
  int r;
  r = read(data, &ret, 4);
  if(r == -1) {printf("%s\n",strerror(errno));}

  //printf("%u\n", ret);
  r = close(data);
  if(r == -1) {printf("%s\n",strerror(errno));}
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
  if(intermed == -1) {printf("%s\n",strerror(errno));}

  int w;
  w = write(intermed, foo, 4*size);
  if(w == -1) {printf("%s\n",strerror(errno));}

  intermed = close(intermed);
  if(intermed == -1) {printf("%s\n",strerror(errno));}

  intermed = open("intermed.txt", O_RDONLY, 0666);
  if(intermed == -1) {printf("%s\n",strerror(errno));}

  unsigned boo[size];
  printf("\nReading numbers from file...\nVerification: \n");
  w = read(intermed, boo, 4*size);
  if(w == -1) {printf("%s\n",strerror(errno));}

  for(i=0; i < size; i++) {
    printf("random %d: %u\n", i, boo[i]);
  }

  //STEP 3:
  return 0;
}
