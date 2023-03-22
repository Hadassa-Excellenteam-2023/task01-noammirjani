#pragma once
#include <cstdio>
#include <stdexcept>

class Vector {
public:

    explicit Vector (size_t = 0, int = 0);
    Vector(const Vector&);
    Vector(Vector&&) noexcept ;
    ~Vector();

    Vector& operator=(const Vector&) noexcept;
    Vector& operator=(Vector&&) noexcept;

    int const* data() const;
    void clear();
    size_t size() const;
    bool empty() const;
    size_t capacity() const;
    void resize();
    void push_back(int);
    void pop_back();
    void insert(size_t, const int);
    void erase(size_t);

    int& operator[](size_t);
    const int& operator[](size_t) const;


private:
    int* m_vector;
    size_t m_size;
    size_t m_capacity;

    //private methods
    void resize(const size_t);
};
