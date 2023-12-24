#include <iostream>
#include <stdexcept>

#include "stack_b.h"
using namespace std;

Stack_B::Stack_B() {
  capacity = 1024;  // initial
  size = 0;
  try {
    stk = new int[capacity];
  } catch (const bad_alloc &) {
    throw runtime_error("Out of Memory");
  }
}

Stack_B::~Stack_B() { delete[] stk; }

void Stack_B::push(int data) {
  if (size >= capacity) {
    int t;
    if (capacity * 2 >= 1024) {
      t = capacity * 2;
      // cout<<t<<endl;
    } else {
      t = 1024;
    }
    int *stk1;
    try {
      stk1 = new int[t];
    } catch (const bad_alloc &) {
      throw runtime_error("Out of Memory");
    }
    for (int i = 0; i < size; i++) {
      stk1[i] = stk[i];
    }
    delete[] stk;
    stk = stk1;
    capacity = t;
  }
  stk[size++] = data;
  // cout<<capacity<<endl;
}

int Stack_B::pop() {
  if (size > 0) {
    int result = get_element_from_top(0);
    size = size - 1;
    if (size <= capacity / 4 && capacity > 1024) {
      int t;
      if (capacity / 2 >= 1024) {
        t = capacity / 2;
        // cout<<t<<endl;
      } else {
        t = 1024;
      }
      int *stk1;
      try {
        stk1 = new int[t];
      } catch (const bad_alloc &) {
        throw runtime_error("Out of Memory");
      }
      for (int i = 0; i < size; i++) {
        stk1[i] = stk[i];
      }
      delete[] stk;
      stk = stk1;
      capacity = t;
    }

    return result;
  } else {
    throw runtime_error("Empty Stack");
  }
  // cout<<capacity<<endl;
}

int Stack_B::get_element_from_top(int idx) {
  if (idx >= 0 && idx < size) {
    return stk[size - idx - 1];
  } else {
    throw runtime_error("Index out of range");
  }
}

int Stack_B::get_element_from_bottom(int idx) {
  if (idx >= 0 && idx < size) {
    return stk[idx];
  } else {
    throw runtime_error("Index out of range");
  }
}

void Stack_B::print_stack(bool top) {
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

int Stack_B::add() {
  if (size >= 2) {
    int first = pop();
    int second = pop();
    push(first + second);
    return get_element_from_top(0);
  } else {
    throw runtime_error("Not Enough Arguments");
  }
}

int Stack_B::subtract() {
  if (size >= 2) {
    int first = pop();
    int second = pop();
    push(second - first);
    return get_element_from_top(0);
  } else {
    throw runtime_error("Not Enough Arguments");
  }
}

int Stack_B::multiply() {
  if (size >= 2) {
    int first = pop();
    int second = pop();
    push(first * second);
    return get_element_from_top(0);
  } else {
    throw runtime_error("Not Enough Arguments");
  }
}

int Stack_B::divide() {
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

int *Stack_B::get_stack() { return stk; }

int Stack_B::get_size() { return size; }

// int main(){
//   Stack_B stk1;
// cout<<stk1.get_size()<<endl;
// // cout<<capacity<<endl;
// for(int i=0;i<5000;i++){
//   stk1.push(5);
// }
// cout<<stk1.get_size()<<endl;
// for(int i=0;i<4000;i++){
//   stk1.pop();
// }
// cout<<stk1.get_size()<<endl;
// }
