#include "../include/acutest.h"

int add(int x, int y) {
  return x + y;
}

void test_add(void) {
  TEST_CHECK_(add(2, 2) == (2 + 2), "add(%d, %d) == %d", 2, 2, (2 + 2));
}

TEST_LIST = {
  { "add(int, int);", test_add },
  {0},
};
