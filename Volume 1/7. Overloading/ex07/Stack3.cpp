//: C06:Stack3.cpp {O}
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Constructors/destructors
#include "Stack3.h"

#include <iostream>

using namespace std;

Stack::Link::Link(void* dat, Link* nxt) {
  data = dat;
  next = nxt;
}

Stack::Link::~Link() { }

Stack::Stack() { head = 0; }

Stack::Stack(void* element, int sz) {

    head = 0;

    for (int i = 0; i < sz; i++)
        this->push( ((string*) element + i) );
}

void Stack::push(void* dat) {
  head = new Link(dat,head);
}

void* Stack::peek() {
  return head->data;
}

void* Stack::pop() {
  if(head == 0) return 0;
  void* result = head->data;
  Link* oldHead = head;
  head = head->next;
  delete oldHead;
  return result;
}

Stack::~Stack() {

} ///:~
