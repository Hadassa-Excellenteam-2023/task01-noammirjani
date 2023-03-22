#include "Vector.h"

//d-tor
Vector::~Vector() {
    clear();
}


//c-tor
Vector::Vector(size_t size, int value)
    : m_size(size), m_vector(new int[size]), m_capacity(size){

    for (auto i = 0; i < (int)size; i++) {
        m_vector[i] = value;
    }
}


//copy c-tor
Vector::Vector(const Vector& other)
    : m_size(other.m_size), m_vector(new int[other.m_capacity]), m_capacity(other.m_capacity){

    for (auto i = 0; i < (int)m_size; i++) {
        m_vector[i] = other.data()[i];
    }
}


//move c-tor - moves the contents of the given vector into a new vector.
Vector::Vector(Vector&& other) noexcept
    : m_size(other.m_size), m_vector(other.m_vector), m_capacity(other.m_capacity) {

    other.m_size = 0;
    other.m_vector = nullptr;
    other.m_capacity = 0;
}


//move assignment - moves the contents of the given vector to the current vector.
Vector& Vector::operator=(Vector&& other) noexcept{

    if(this != &other) {
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_vector = other.m_vector;

        other.m_size = 0;
        other.m_capacity = 0;
        other.m_vector = nullptr;
    }

    return *this;
}


//copy assignment - copies the contents of the given vector to the current vector.
Vector& Vector::operator=(const Vector& other) noexcept{

    if(this == &other) return *this;

    delete[] m_vector;
    m_size = other.m_size;
    m_vector = new int[m_size];
    m_capacity = other.m_capacity;

    for (auto i = 0; i < (int)m_size; i++) {
        m_vector[i] = other.data()[i];
    }

    return *this;
}


// getters
bool Vector::empty() const {
    return m_size == 0;
}

int const* Vector::data() const {
    return m_vector;
}

size_t Vector::size() const {
    return m_size;
}

size_t Vector::capacity() const {
    return m_capacity;
}


//options on the vector
//Clears the vector and deallocates the memory.
void Vector::clear(){
    delete[] m_vector;
    m_vector = nullptr;
    m_size = 0;
    m_capacity = 1;
}


//Doubles the capacity of the vector if the current size is equal to the capacity.
void Vector::resize(){
    if(m_capacity > m_size) return;
    resize(m_capacity == 0 ? 1 : m_capacity * 2);
}


//Resizes the vector to the given capacity, copies the data.
void Vector::resize(const size_t newCapacity) {
    int* temp = new int[newCapacity];

    for (auto i = 0; i < m_size; ++i) {
        temp[i] = m_vector[i];
    }

    m_capacity = newCapacity;
    delete[] m_vector;
    m_vector = temp;
}


//Adds a new element to the end of the vector.
void Vector::push_back(const int value){
    if (m_size == m_capacity) resize();

    m_vector[m_size++] = value;
}


//Removes the last element of the vector.
void Vector::pop_back(){
    if(m_size <= 0) return;

    --m_size;
     m_vector[m_size] = 0;

    if(m_size < m_capacity/2) {
        resize(m_capacity/2);
    }

    if(m_size == 0) {
        m_capacity = 1;
        m_vector = nullptr;
    }
}


//Inserts a new element at the given position.
void Vector::insert(size_t target, const int value) {

    if(target > m_size + 1 || target < 0)
        throw std::out_of_range("Index out of range");

    if (m_size == m_capacity) resize();

    for (auto i = m_size; i > target; --i) {
        m_vector[i] = m_vector[i-1];
    }
    m_vector[target] = value;
    ++m_size;
}


//Removes the element at the given position.
void Vector::erase(size_t target) {
    if(target > m_size-1 || target < 0) {
        throw std::out_of_range("Index out of range");
    }

    for (auto i = target; i < m_size; ++i) {
        m_vector[i] = m_vector[i+1];
    }

    m_vector[--m_size] = 0;

    if(m_size < m_capacity/2) {
        resize(m_capacity/2);
    }
}


//Returns the element at the given position.
int& Vector::operator[](size_t index) {

    if(index > m_size-1 || index < 0) throw std::out_of_range("Index out of range");
    return m_vector[index];
}


//Returns the element at the given position.
const int& Vector::operator[](size_t index) const {

    if(index > m_size-1 || index < 0) throw std::out_of_range("Index out of range");
    return m_vector[index];
}