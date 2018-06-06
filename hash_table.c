#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LINE_LENGTH 512

// The constant values and hash function are taken from 
// Introduction to Algorithms, Stein et al.
// Size of the symbol table. Should be a prime number large
// enough to have good performance for medium size programs
static const uint32_t tableSize = 109;
// Processor wordsize
static const uint32_t wordSize = 32;
// A is a fraction of the form s/2^(wordSize) where s is an
// integer in the range 0 < s < 2^w. A is currently the fraction
// closest to (root(5) - 1)/2.
static const uint32_t s = 2654435769;

uint32_t hash(const char key[MAX_LINE_LENGTH]) {
  float A = s/pow(2, wordSize);
  uint32_t keyInt;
  for (int i = 0; i < MAX_LINE_LENGTH; i++) {
    keyInt += (key[i] * i);
  }
  return floor(tableSize * ((A * keyInt) - (uint32_t) (A * keyInt)));
}

int main(void) {
  char y[MAX_LINE_LENGTH] = "abcdefeefnrfnrkgnbkjvbgkjbvnsliergkvnkjtnrwb"; 
  printf("%u\n", hash(y));
  return 0;
}
