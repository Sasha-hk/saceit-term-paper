#include "../include/acutest.h"
#include "../include/stack.h"
#include "../include/date.h"
#include <iostream>
#include <string>

using namespace std;

// STACK testing
void test_constructor(void) {
  // Int
  Stack<int> intStack = Stack<int>();

  TEST_CHECK_(intStack.getTop() == 0, "top == %d", 0);
  TEST_CHECK_(intStack.size() == 10, "top == %d", 10);

  // String
  Stack<string> stringStack = Stack<string>();

  TEST_CHECK_(stringStack.getTop() == 0, "top == %d", 0);
  TEST_CHECK_(stringStack.size() == 10, "top == %d", 10);
}

void test_constructor_with_capacity(void) {
  // Int
  int intStackSize = 1;
  Stack<int> intStack = Stack<int>(intStackSize);

  TEST_CHECK_(intStack.getTop() == 0, "top == %d", 0);
  TEST_CHECK_(intStack.size() == intStackSize, "top == %d", intStackSize);

  // String
  int stringStackSize = 100;
  Stack<string> stringStack = Stack<string>(stringStackSize);

  TEST_CHECK_(stringStack.getTop() == 0, "top == %d", 0);
  TEST_CHECK_(stringStack.size() == stringStackSize, "top == %d", stringStackSize);
}

void test_actions(void) {
  int size = 5;
  Stack<int> stack = Stack<int>(size);

  stack.push(287);

  TEST_CHECK_(stack.peek() == 287, "stack.peek() == %d", 287);
  TEST_CHECK_(stack.pop() == 287, "stack.pop() == %d", 287);
  TEST_CHECK_(stack.getTop() == 0, "stack.getTop() == 0");
  TEST_CHECK_(stack.isEmpty() == true, "stack.isEmpty() == true");
  TEST_CHECK_(stack.isFull() == false, "stack.isFull() == false");

  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.push(4);
  stack.push(5);

  TEST_CHECK_(stack.isFull() == true, "stack.isFull() == true");
  TEST_CHECK_(stack.getTop() == 5, "stack.getTop() == %d", size);
  TEST_CHECK_(stack.isEmpty() == false, "stack.isEmpty() == false");
  TEST_CHECK_(stack.size() == size, "stack.size() == %d", size);

  stack.push(6);

  TEST_CHECK_(stack.size() == size * 2, "stack.size() == %d", size * 2);
  TEST_CHECK_(stack.pop() == 6, "stack.peek() == %d", 6);

  size *= 2;

  stack.push(6);
  stack.push(7);
  stack.push(8);
  stack.push(9);
  stack.push(10);

  for (int i = size; i > 0; i--) {
    TEST_CHECK_(stack.pop() == i, "stack.pop() == %d", i);
  }
}

TEST_LIST = {
  // STACK tests
  { "Stack<type>();", test_constructor },
  { "Stack<type>(int);", test_constructor_with_capacity },
  { "stack.push / pop / peek();", test_actions },
  {0},
};
