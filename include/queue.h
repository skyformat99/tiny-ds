#ifndef ALG_QUEUE_H_
#define ALG_QUEUE_H_

#include <stdint.h>
#include <exception>

namespace alg {
    template<typename T>
        class Queue {
            private:
                class QueueEmptyException: public std::exception {
                    public:
                        // const throw()   need to figure out
                        virtual const char * what() const throw() {
                            return  "Queue is empty";
                        }
                } excep_empty;

            private:
                // queue capacity;
                uint32_t m_capacity;
                // current queue size
                uint32_t m_size;
                // index of first element
                uint32_t m_front;
                // index of last element
                uint32_t m_rear;
                // the elements
                T * m_elements;

            public:
                Queue(uint32_t max) {
                    this->m_elements = new T[max];
                    this->m_size = 0;
                    this->m_capacity = max;
                    this->m_front = 0;
                    this->m_rear = -1;
                };

                ~Queue() {
                    delete[] m_elements;
                };

            private:
                // C++11  can use delete ?
                Queue(const Queue &);
                Queue& operator=(const Queue &);

            public:
                inline void dequeue() {
                    if (m_size == 0) {
                        return;
                    } else {
                        m_size --;
                        m_front ++;
                        if (m_front == m_capacity) {
                            m_front = 0;
                        }
                        return;
                    }
                };

                inline const T& front() const {
                    if (m_size == 0) throw excep_empty;
                    return m_elements[m_front];
                };

                inline bool is_empty() const {
                    if (m_size == 0) return true;
                    return false;
                };

                bool enqueue(const T& element) {
                    if (m_size == m_capacity) 
                        return false;
                    else {
                        m_size ++;
                        m_rear ++;
                        if (m_rear == m_capacity) {
                            m_rear = 0;
                        }
                        m_elements[m_rear] = element;
                        return true;
                    }
                };

                inline uint32_t count() const {
                    return m_size;
                };

                inline uint32_t capacity() const {
                    return m_capacity;
                };
        };
}
#endif
