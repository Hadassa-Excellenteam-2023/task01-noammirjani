#pragma once
#include <stdexcept>

class Stack {
public:
    explicit Stack(size_t size = 0, int value = 0);
    Stack(const Stack& other);
    Stack(Stack&& other) noexcept;
    ~Stack();
    Stack& operator=(const Stack& other);
    Stack& operator=(Stack&& other) noexcept;
    void push(int value);
    int pop();
    bool is_empty() const;
    bool operator==(const Stack&) const;
    bool operator!=(const Stack&) const;
    bool operator<(const Stack&) const;
    bool operator>(const Stack&) const;
    Stack operator+(const Stack&) const;
    Stack& operator+=(const Stack&);
    Stack& operator+=(const int);
    Stack& operator-=(const int);
    Stack& operator*=(const int);
    Stack& operator/=(const int);

private:
    int* m_stack;
    int m_top;
    size_t m_max;

    bool is_full() const;
    void resize(size_t new_size);
};
