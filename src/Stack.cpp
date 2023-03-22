#include "Stack.h"

//c-tor
Stack::Stack(size_t size, int value)
    : m_stack(new int[size]), m_top((int)size - 1), m_max(size) {
    for (auto i = 0; i < (int)size; i++) {
        m_stack[i] = value;
    }
}

//copy c-tor
Stack::Stack(const Stack& other)
    : m_stack(new int[other.m_max]), m_top(other.m_top), m_max(other.m_max) {

    for (auto i = 0; i <= (int)m_top; i++) {
        m_stack[i] = other.m_stack[i];
    }
}

//move c-tor
Stack::Stack(Stack&& other) noexcept
    : m_stack(other.m_stack), m_top(other.m_top), m_max(other.m_max) {
    other.m_stack = nullptr;
    other.m_top = -1;
    other.m_max = 0;
}

//d-tor
Stack::~Stack() {
    delete[] m_stack;
}

//copy assignment
Stack& Stack::operator=(const Stack& other) {
    if (this == &other) return *this;

    delete[] m_stack;
    m_stack = new int[other.m_max];
    m_top = other.m_top;
    m_max = other.m_max;

    for (auto i = 0; i < m_top+1; i++) {
        m_stack[i] = other.m_stack[i];
    }

    return *this;
}

//move assignment
Stack& Stack::operator=(Stack&& other) noexcept {
    if (this != &other) {
        delete[] m_stack;

        m_stack = other.m_stack;
        m_top = other.m_top;
        m_max = other.m_max;

        other.m_stack = nullptr;
        other.m_top = -1;
        other.m_max = 0;
    }

    return *this;
}

//push
void Stack::push(int value) {

    if(is_full()) resize(m_max ? m_max * 2 : 1);

    m_stack[++m_top] = value;
}

//is_full Returns true if the Stack is full, false otherwise.
bool Stack::is_full() const {
    return m_top == (int)m_max - 1;
}

//resize Resizes the Stack to the specified size.
void Stack::resize(size_t new_size){
    if(new_size < 1) return;
    int* new_stack = new int[new_size];
    for (auto i = 0; i < m_top + 1; i++) {
        new_stack[i] = m_stack[i];
    }
    delete[] m_stack;
    m_stack = new_stack;
    m_max = new_size;
}

//pop Removes the top element from the Stack and returns it.
int Stack::pop() {
    if (is_empty()) throw std::runtime_error("Stack is empty");
    if (m_top-1 < (int)m_max / 4) resize(m_max / 2);

    auto ret = m_stack[m_top];
    m_top--;
    if(m_top == -1) m_stack = nullptr;
    return ret;
}

//is_empty Returns true if the Stack is empty, false otherwise.
bool Stack::is_empty() const {
    return m_top == -1 || m_max == 0;
}

//operator== Compares the contents of two Stacks for equality.
bool Stack::operator==(const Stack& other) const {
    if (m_top != other.m_top) return false;

    for (auto i = 0; i < m_top + 1; i++) {
        if (m_stack[i] != other.m_stack[i]) return false;
    }
    return true;
}

//operator!= Compares the contents of two Stacks for inequality.
bool Stack::operator!=(const Stack& other) const {
    return !(*this == other);
}

//operator< Determines if one Stack is less than another
bool Stack::operator<(const Stack& other) const {

    return m_top < other.m_top;
}

//operator> Determines if one Stack is greater than another
bool Stack::operator>(const Stack& other) const {
    return  other < *this;
}

//operator+= Appends the contents of one Stack to another.
Stack& Stack::operator+=(const Stack& other) {
    for (int i = 0; i < other.m_top+1; i++) {
        push(other.m_stack[i]);
    }
    return *this;
}

//operator+ Returns a new Stack that is the concatenation of two Stacks
Stack Stack::operator+(const Stack& other) const {

    Stack result(*this);
    result += other;
    return result;
}

//operator+= Adds a value to each element of the Stack.
Stack& Stack::operator+=(const int value) {

    for(int i = m_top; i >= 0; i--){
        m_stack[i] += value;
    }
    return *this;
}

//operator-= Subtracts a value from each element of the Stack.
Stack& Stack::operator-=(const int value) {

    for(int i = m_top; i >= 0; i--){
        m_stack[i] -= value;
    }
    return *this;
}

//operator*= Multiplies each element of the Stack by a value.
Stack& Stack::operator*=(const int value) {

    for(int i = m_top; i >= 0; i--){
        m_stack[i] *= value;
    }
    return *this;
}

//operator/= Divides each element of the Stack by a value.
Stack& Stack::operator/=(const int value) {

    for(int i = m_top; i >= 0; i--){
        m_stack[i] /= value;
    }
    return *this;
}