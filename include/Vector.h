#pragma once
#include <cstdio>
#include <stdexcept>
#include <utility>

class Vector {
public:
    //constructors
    explicit Vector (size_t = 0, int = 0);
    Vector(const Vector&);
    Vector(Vector&&) noexcept;

    //destructor
    ~Vector();

    //operators
    Vector& operator=(const Vector&) noexcept;
    Vector& operator=(Vector&&)      noexcept;
    int& operator[](size_t);
    const int& operator[](size_t)   const;
    bool operator==(const Vector&)  const;
    bool operator!=(const Vector&)  const;

    //methods
    [[nodiscard]] int const* data() const;
    [[nodiscard]] size_t size()     const;
    [[nodiscard]] bool empty()      const;
    [[nodiscard]] size_t capacity() const;
    void clear();
    void resize();
    void resize(const size_t);
    void insert(size_t, const int);
    void erase(size_t);
    void swap(Vector&);

    //push and pop
    void push_back(int);
    void push_front(int);
    void pop_back();
    void pop_front();

private:
    int* m_vector;
    size_t m_size;
    size_t m_capacity;

    //private methods


};
