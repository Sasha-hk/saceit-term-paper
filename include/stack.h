#pragma stack
#ifndef STACK_H
#define STACK_H

#include <vector>

using std::vector;

/**
 * Stack data structure
 */
template <class Type> class Stack {
  private:
    vector<Type> stack;
    int capacity;
    int top;

  public:
    /**
     * Defalt constructor
     */
    Stack() {
      this->capacity = 10;
      this->top = 0;
    }

    /**
     * Stack constructor
     * @param capacity Max count of items before expanding the stack
     */
    Stack(int capacity) {
      this->top = 0;
      this->capacity = capacity;
      this->stack = vector<Type>(capacity);
    }

    /**
     * Push data to stack
     * @param data Data
     */
    void push(Type data) {
      if (top == capacity) {
        this->capacity = capacity * 2;
        this->stack[top] = data;
        this->top++;
      }
      else {
        this->stack[this->top] = data;
        this->top++;
      }
    }

    /**
     * Pop item
     */
    Type pop() {
      this->top--;
      return this->stack[this->top];
    }

    /**
     * Peek item
     */
    Type peek() {
      return this->stack[this->top - 1];
    }

    /**
     * Check if stack is full
     */
    bool isFull() {
      return this->capacity == this->top;
    }

    /**
     * Check if stack if full
     */
    bool isEmpty() {
      return 0 == this->top;
    }

    /**
     * Get currect max size
     */
    int size() {
      return this->capacity;
    }

    /**
     * Get current top
     */
    int getTop() {
      return this->top;
    }
};

#endif
