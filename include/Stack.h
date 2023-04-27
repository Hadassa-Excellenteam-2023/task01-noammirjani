#pragma once
#include <stdexcept>
#include "Vector.h"

class Stack {
public:
    //constructors
    explicit Stack(size_t size = 1, int value = 0);
    Stack(const Stack& other);
    Stack(Stack&& other) noexcept;

    //destructor
    ~Stack();

    //assignment operators
    Stack& operator=(const Stack& other);
    Stack& operator=(Stack&& other) noexcept;

    //accessors
    void push(int value);
    int pop();
    bool is_empty() const;

    //operators
    bool operator==(const Stack&) const;
    bool operator!=(const Stack&) const;
    bool operator<(const Stack&) const;
    bool operator>(const Stack&) const;
    Stack operator+(const Stack&) const;

    //arithmetic operators
    Stack& operator+=(const Stack&);
    Stack& operator+=(const int);
    Stack& operator-=(const int);
    Stack& operator*=(const int);
    Stack& operator/=(const int);

private:
    Vector m_stack; //vector to store stack elements and size
    const int TOP = 0; //index of top element

};
