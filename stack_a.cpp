#include <iostream>
#include <stdexcept>

#include "stack_a.h"
using namespace std;

Stack_A::Stack_A() { size = 0; }

void Stack_A::push(int data) {
  if (size < 1024) {
    stk[size++] = data;
  } else {
    throw runtime_error("Stack Full");
  }
}
// size=1024
// index of array 0 to 1023

int Stack_A::pop() {
  if (size > 0) {
    return stk[--size];
  } else {
    throw runtime_error("Empty Stack");
  }
}

int Stack_A::get_element_from_top(int idx) {
  if (idx >= 0 && idx < size) {
    return stk[size - idx - 1];
  } else {
    throw runtime_error("Index out of range");
  }
}

int Stack_A::get_element_from_bottom(int idx) {
  if (idx >= 0 && idx < size) {
    return stk[idx];
  } else {
    throw runtime_error("Index out of range");
  }
}

void Stack_A::print_stack(bool top) {
  if (!top) {
    for (int i = 0; i < size; i++) {
      cout << stk[i] << endl;
    }
  } else {
    for (int i = size - 1; i >= 0; i--) {
      cout << stk[i] << endl;
    }
  }
  cout << endl;
}

int Stack_A::add() {
  if (size >= 2) {
    int first = pop();
    int second = pop();
    push(first + second);
    return get_element_from_top(0);
  } else {
    throw runtime_error("Not Enough Arguments");
  }
}

int Stack_A::subtract() {
  if (size >= 2) {
    int first = pop();
    int second = pop();
    push(second - first);
    return get_element_from_top(0);
  } else {
    throw runtime_error("Not Enough Arguments");
  }
}

int Stack_A::multiply() {
  if (size >= 2) {
    int first = pop();
    int second = pop();
    push(first * second);
    return get_element_from_top(0);
  } else {
    throw runtime_error("Not Enough Arguments");
  }
}

int Stack_A::divide() {
  if (size >= 2) {
    int first = pop();
    int second = pop();
    if (first == 0) {
      throw runtime_error("Divide by Zero Error");
    } else {
      if ((second % first != 0) && ((first * second < 0))) {
        push(second / first - 1);
      } else {
        push(second / first);
      }
    }
    return get_element_from_top(0);
  } else {
    throw runtime_error("Not Enough Arguments");
  }
}

int *Stack_A::get_stack() { return stk; }

int Stack_A::get_size() { return size; }