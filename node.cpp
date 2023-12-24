#include <iostream>
#include <stdexcept>

#include "node.h"
using namespace std;

Node::Node(bool sentinel) {
  this->is_sentinel = sentinel;
  if (this->is_sentinel == true) {
    this->prev = NULL;
    this->next = NULL;
  }
}

Node::Node(int v, Node *nxt, Node *prv) {
  this->is_sentinel = false;
  this->prev = prv;
  this->value = v;
  this->next = nxt;
}

bool Node::is_sentinel_node() { return this->is_sentinel; }

int Node::get_value() { return this->value; }
