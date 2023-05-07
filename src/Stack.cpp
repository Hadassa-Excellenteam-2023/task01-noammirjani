#include "Stack.h"

//------ c-tors d-tor assign operator ---------------
//constructor
Stack::Stack(size_t size, int value)
    : m_stack(size, value) {}


//copy constructor
Stack::Stack(const Stack& other)
    : m_stack(other.m_stack) {}


//move constructor
Stack::Stack(Stack&& other) noexcept
    : m_stack(std::move(other.m_stack)) {}


//copy assignment operator
Stack& Stack::operator=(const Stack& other) {
    if (this != &other) m_stack = other.m_stack;
    return *this;
}


//move assignment operator
Stack& Stack::operator=(Stack&& other) noexcept {
    if (this != &other) m_stack = std::move(other.m_stack);
    return *this;
}


//---------------  accessors ------------------------
void Stack::push(int value) {
    m_stack.push_back(value);
}


int Stack::pop() {
    if (is_empty()) throw std::out_of_range("Stack is empty");
    int result = m_stack[m_stack.size() - 1];
    m_stack.pop_back();
    return result;
}


//is_empty - returns true if stack is empty
bool Stack::is_empty() const {
    return m_stack.empty();
}


//---------------  operators ------------------------
bool Stack::operator==(const Stack& other) const {
    return m_stack == other.m_stack;
}


bool Stack::operator!=(const Stack& other) const {
    return !(*this == other);
}


bool Stack::operator<(const Stack& other) const {
    return m_stack.size() < other.m_stack.size();
}


bool Stack::operator>(const Stack& other) const {
    return other < *this;
}


Stack Stack::operator+(const Stack& other) const {
    Stack result(*this);
    result += other;
    return result;
}


Stack& Stack::operator+=(const Stack& other) {
    for (auto i = 0; i < other.m_stack.size(); i++) {
        push(other.m_stack[i]);
    }
    return *this;
}


//-------------- arithmetic operators ---------------
Stack& Stack::operator+=(const int value) {
    for (size_t i = 0; i < m_stack.size(); i++) {
        m_stack[i] += value;
    }
    return *this;
}


Stack& Stack::operator-=(const int value) {

    *this += -value;
    return *this; 
}


Stack& Stack::operator*=(const int value) {
    for (auto i = 0; i < m_stack.size(); i++) {
        m_stack[i] *= value;
    }
    return *this;
}


Stack& Stack::operator/=(const int value) {

    if(value == 0)  throw std::runtime_error("can not divide by 0");

    for (auto i = 0; i < m_stack.size(); i++) {
        m_stack[i] /= value;
    }
    return *this;
}