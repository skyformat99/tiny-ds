#ifndef ALG_STACK_H_
#define ALG_STACK_H_

#include <exception>

namespace alg {
    template<typename T>
        class Stack {
            private:
                class StackEmptyException: public std::exception {
                    public:
                        virtual const char* what() const throw(){
                            return "empty stack";
                        }
                } excp_empty;

                class StackIndexOutOfBoundException: public std::exception {
                    public:
                        virtual const char* what() const throw(){
                            return "index out of bound";
                        }
                } excp_ioob;

                uint32_t m_capacity;
                uint32_t m_size;
                T * m_elements;

            public:
                Stack(uint32_t capacity) {
                    this-> m_capacity = capacity;
                    this-> m_size = 0;
                    this-> m_elements = new T[capacity];
                }
                ~Stack() {
                    delete [] m_elements;
                }
            
            private:
                Stack(const Stack&);
                Stack& operator= (const Stack&);

            public:
                inline bool is_empty() const {return m_size == 0? true: false;}
                inline void pop() {if (m_size != 0) m_size--; return;};
                inline const T& top() const {
                    if (m_size == 0) throw excp_empty;
                    return m_elements[m_size-1];
                }

                inline bool push(const T& value) {
                    if (m_size == m_capacity) {
                        return false;
                    } else {
                        m_elements[m_size++] = value;
                        return true;
                    }
                }

                inline uint32_t count() const {return m_size;}

                inline const T& operator[](uint32_t idx) const {
                    if (idx >= m_capacity) throw excp_ioob;
                    return m_elements[m_size-1-idx];
                }
        };
}
#endif
