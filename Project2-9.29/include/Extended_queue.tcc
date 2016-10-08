// Write by longj on 2016.10.05
// The basic queue we use in the project
// #include <cstring>
// #include "Extended_queue.hpp"
/*本队列使用的是循环队列，通过给出一个空的位来区分队列满和队列空的情况*/

template <typename ElementType>
Extended_queue<ElementType>::Extended_queue() : m_front(0), m_rear(0) {
  memset(m_buffer, 0, maxsize);
}

template <typename ElementType>
int Extended_queue<ElementType>::size() const {
  return (m_rear < m_front) ? (m_rear - m_front + maxsize) : (m_rear - m_front);
}

template <typename ElementType>
Error_code Extended_queue<ElementType>::push(const ElementType &item) {
  if (isFull()) {
    return overflow;
  }
  m_buffer[m_rear] = item;
  m_rear = (m_rear + 1) % maxsize;
  return success;
}

template <typename ElementType>
Error_code Extended_queue<ElementType>::pop() {
  if (isEmpty()) {
    return underflow;
  }
  m_front = (m_front + 1) % maxsize;
  return success;
}

/**
 * Get the front element of the current queue into a reference variabl
 * @param  item a ElementType reference to store the front element
 * @return if successful return a success Error_code
 */
template <typename ElementType>
Error_code Extended_queue<ElementType>::retrieve(ElementType &item) const {
  if (isEmpty()) {
    return underflow;
  }
  item = m_buffer[m_front];
  return success;
}

template <typename ElementType>
Extended_queue<ElementType>::~Extended_queue() {
  m_front = m_rear = 0;
}
