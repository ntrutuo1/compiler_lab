#include <stdio.h>
#include <stdlib.h>

int scan(char *fileName);

int main(void) {
  if (scan("../test/example2.kpl") == 0) {
    return 0;
  }
  return 1;
}
