// Write by longj on 2016.10.05
// The basic queue we use in the project

#ifndef EXTENDED_QUEUE_HPP_
#define EXTENDED_QUEUE_HPP_

#include <cstring>
#include "enum.hpp"
// the max number of the content is 500
const int maxsize = 501;

/*本队列使用的是循环队列，通过给出一个空的位来区分队列满和队列空的情况*/
template <typename ElementType>
class Extended_queue {
 public:
  Extended_queue();
  ~Extended_queue();

  // 这个队列的rear是指向最后一个元素的后一个区域
  // 所以，队空的时候应该是 rear == front
  // 队满的时候应该是 （rear+1）% maxsize == front
  bool isEmpty() const { return (m_front == m_rear); }
  bool isFull() const { return (m_rear + 1) % maxsize == m_front; }
  int size() const;

  // 基本操作
  Error_code push(const ElementType& item);
  Error_code pop();
  /**
   * Get the front element of the current queue into a reference variabl
   * @param  item a Queue_Element reference to store the front element
   * @return if successful return a success Error_code
   */
  Error_code retrieve(ElementType& item) const;

 private:
  int m_front;
  int m_rear;
  ElementType m_buffer[maxsize];
};

#include "Extended_queue.tcc"

#endif
