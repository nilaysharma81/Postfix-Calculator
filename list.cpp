#include <iostream>
#include <stdexcept>

#include "list.h"
using namespace std;

List::List() {  // initializes the list
  sentinel_head = new Node(true);
  sentinel_tail = new Node(true);
  size = 0;
  sentinel_tail->prev = sentinel_head;
  sentinel_head->next = sentinel_tail;
}

List::~List() {
  // delete sentinel_head,inner nodes and sentinel_tail;
  if (size != 0) {
    Node *node1 = sentinel_head->next;
    while (node1->next != sentinel_tail) {
      Node *temp1 = node1->next;
      delete node1;
      node1 = temp1;
    }
    // node1->next=sentinel_tail;
    delete node1;
    delete sentinel_head;
    delete sentinel_tail;
  } else {
    delete sentinel_head;
    delete sentinel_tail;
  }
}

void List::insert(int v) {
  Node *node1 = new Node(v, sentinel_tail, sentinel_tail->prev);
  size = size + 1;
  // cout<<"Here"<<endl;
  sentinel_tail->prev->next = node1;
  node1->prev = sentinel_tail->prev;
  sentinel_tail->prev = node1;
  node1->next = sentinel_tail;
}

int List::delete_tail() {
  if (size == 0) {
    throw runtime_error("Empty Stack");
  }

  else {
    Node *node1 = sentinel_tail->prev;
    int val = node1->get_value();
    if (size == 1) {
      size = 0;
      sentinel_tail->prev = sentinel_head;
      sentinel_head->next = sentinel_tail;
      delete node1;
      return val;
    } else {
      size = size - 1;
      sentinel_tail->prev->prev->next = sentinel_tail;
      sentinel_tail->prev = sentinel_tail->prev->prev;
      delete node1;
      return val;
    }
  }
}

int List::get_size() { return size; }

Node *List::get_head() { return sentinel_head; }
