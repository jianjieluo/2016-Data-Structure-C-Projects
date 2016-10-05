// Write by longj on 2016.10.05
// The basic queue we use in the project

#include "Extended_queue.hpp"
#include <cstring>
/*本队列使用的是循环队列，通过给出一个空的位来区分队列满和队列空的情况*/

Extended_queue::Extended_queue() : m_front(0), m_rear(0) {
  memset(m_buffer, 0, maxsize);
}

int Extended_queue::size() const {
  return (m_rear < m_front) ? (m_rear - m_front + maxsize) : (m_rear - m_front);
}

Error_code Extended_queue::push(const Queue_Element &item) {
  if (isFull()) {
    return overflow;
  }
  m_buffer[m_rear] = item;
  m_rear = (m_rear + 1) % maxsize;
  return success;
}

Error_code Extended_queue::pop() {
  if (isEmpty()) {
    return underflow;
  }
  m_front = (m_front + 1) % maxsize;
  return success;
}

/**
 * Get the front element of the current queue into a reference variabl
 * @param  item a Queue_Element reference to store the front element
 * @return if successful return a success Error_code
 */
Error_code Extended_queue::retrieve(Queue_Element &item) const {
  if (isEmpty()) {
    return underflow;
  }
  item = m_buffer[m_front];
  return success;
}
