#include <iostream>
#include <stdexcept>

#include "list.h"
#include "stack_c.h"
using namespace std;

Stack_C::Stack_C() {
  try {
    stk = new List();
  } catch (const bad_alloc&) {
    throw runtime_error("Out of Memory");
  }
};

Stack_C::~Stack_C() { delete stk; };

void Stack_C::push(int data) { stk->insert(data); };

int Stack_C::pop() {
  if (stk->get_size() != 0) {
    return stk->delete_tail();
  } else {
    throw runtime_error("Empty Stack");
  }
};

int Stack_C::get_element_from_top(int idx) {
  // cout<<"Inside get "<<this->get_size()<<endl;
  int index = stk->get_size() - idx - 1;
  return get_element_from_bottom(index);
};

int Stack_C::get_element_from_bottom(int idx) {
  if (idx < 0 || idx > stk->get_size()) {
    throw runtime_error("Index out of range");
  } else {
    Node* node1 = (stk->get_head())->next;
    int index = 0;
    while (index != idx) {
      node1 = node1->next;
      index = index + 1;
    }
    // cout<<"hi"<<endl;
    // cout<<node1->get_value()<<endl;
    return node1->get_value();
  }
};

void Stack_C::print_stack(bool top) {
  if (!top) {
    Node* node1 = (stk->get_head())->next;
    while (!node1->is_sentinel_node()) {
      // cout << node1->get_value() << endl;
      node1 = node1->next;
    }
  } else {
    Node* node2 = (stk->get_head())->next;
    while (!(node2->next)->is_sentinel_node()) {
      node2 = node2->next;
    }
    while (!node2->is_sentinel_node()) {
      // cout << node2->get_value() << endl;
      node2 = node2->prev;
    }
  }
};

int Stack_C::add() {
  if (stk->get_size() >= 2) {
    // cout<<"Here"<<endl;
    int first = stk->delete_tail();
    int second = stk->delete_tail();
    // cout<<first+second<<endl;
    stk->insert(first + second);
    return get_element_from_top(0);
  } else {
    throw runtime_error("Not Enough Arguments");
  }
};

int Stack_C::subtract() {
  if (stk->get_size() >= 2) {
    int first = stk->delete_tail();
    int second = stk->delete_tail();
    stk->insert(second - first);
    return get_element_from_top(0);
  } else {
    throw runtime_error("Not Enough Arguments");
  }
};

int Stack_C::multiply() {
  if (stk->get_size() >= 2) {
    int first = stk->delete_tail();
    int second = stk->delete_tail();
    stk->insert(first * second);
    return get_element_from_top(0);
  } else {
    throw runtime_error("Not Enough Arguments");
  }
};

int Stack_C::divide() {
  if (stk->get_size() >= 2) {
    int first = stk->delete_tail();
    int second = stk->delete_tail();
    if (first == 0) {
      throw runtime_error("Divide by Zero Error");
    } else {
      if ((second % first != 0) && ((first * second < 0))) {
        stk->insert(second / first - 1);
      } else {
        stk->insert(second / first);
      }
    }
    return get_element_from_top(0);
  } else {
    throw runtime_error("Not Enough Arguments");
  }
};

List* Stack_C::get_stack() { return stk; };

int Stack_C::get_size() { return stk->get_size(); };

// int main()
// {
//   Stack_C temp;
//   temp.push(2);
//   temp.push(10);
//   temp.push(-6);
//   temp.push(4);
//   temp.push(-15);
//   temp.push(4);
//   temp.push(5);
//   temp.push(11);
//   temp.push(-9);
//   temp.push(-7);
//   cout<<temp.get_size()<<endl;
//   cout<<temp.add()<<endl;
//   cout<<temp.add()<<endl;
//   cout<<temp.add()<<endl;
//   cout<<temp.subtract()<<endl;
//   cout<<temp.subtract()<<endl;
//   cout<<temp.divide()<<endl;
//   cout<<temp.divide()<<endl;
//   cout<<temp.multiply()<<endl;
//   cout<<temp.multiply()<<endl;
// Stack_C temp;
// cout<<temp.get_size()<<endl;
// for(int i=0;i<5000;i++){
//   temp.push(5);
// }
// cout<<temp.get_size()<<endl;
// for(int i=0;i<4000;i++){
//   temp.pop();
// }
// cout<<temp.get_size()<<endl;
// }