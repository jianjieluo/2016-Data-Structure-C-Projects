#ifndef QUEUE_HPP_
#define QUEUE_HPP_

#include <cstring>
#include <iostream>
#include "Error_code.hpp"
#define MAX 301
// the max number of the content is 300

typedef char Queue_entry;

class Queue {
 public:
  Queue();
  ~Queue();
  bool full() const;
  bool empty() const;
  Error_code push(const Queue_entry data);
  Error_code pop();
  Error_code display() const;

 private:
  char buffer[MAX];
  int front;
  int rear;
};

#endif
