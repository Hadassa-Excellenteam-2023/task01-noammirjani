#include "Vector.h"

//------ c-tord, d-tor, assign operator ---------
//destructor
Vector::~Vector() {
    clear();
}


//constructor
Vector::Vector(size_t size, int value)
    : m_size(size), m_vector(new int[size]), m_capacity(size ? size : 1) {

    for (size_t i = 0; i < size; i++) {
        m_vector[i] = value;
    }
}


//copy constructor
Vector::Vector(const Vector& other)
    : m_size(other.size()), m_vector(new int[other.capacity()]), m_capacity(other.m_capacity) {

    for (size_t i = 0; i < m_size; i++) {
        m_vector[i] = other.data()[i];
    }
}


//move constructor - moves the contents of the given vector into a new vector.
Vector::Vector(Vector&& other) noexcept 
    : Vector() {
    swap(other);
}


//copy assignment - copies the contents of the given vector to the current vector.
Vector& Vector::operator=(const Vector& other) noexcept{
    Vector temp(other);
    swap(temp); 
    return *this;
}


//move assignment - moves the contents of the given vector to the current vector.
Vector& Vector::operator=(Vector&& other) noexcept{

    if(this != &other) {
        m_size = other.size();
        m_capacity = other.capacity();
        m_vector = other.m_vector;

        other.m_size = 0;
        other.m_capacity = 0;
        other.m_vector = nullptr;
    } 

    return *this;
}


//------------------ methods --------------------
//Adds a new element to the end of the vector.
void Vector::push_back(const int value){
    if (m_size == m_capacity) resize();

    m_vector[m_size++] = value;
}


//Removes the last element of the vector.
void Vector::pop_back(){
    
    --m_size;
    m_vector[m_size] = 0;


    if(m_size == 0) {
        m_capacity = 1;
        m_vector = nullptr;
    }
}


void Vector::push_front(int i) {
    insert(0, i);
}


void Vector::pop_front() {
    erase(0);
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


//Resizes the vector to capacity that fits the current capacity
void Vector::resize() {
    if(m_capacity > m_size) return;

    if(m_capacity == 0)        m_capacity = 1;
    else if(m_capacity >= 128) m_capacity *= 1.5;
    else                       m_capacity *= 2;

    resize(m_capacity);
}



//Resizes the vector to the given capacity -
// can shrink or multiple capacity, copies the data.
void Vector::resize(const size_t newCapacity) {
    if(newCapacity < 0) std::out_of_range("capacity out of range");

    int* temp = new int[newCapacity];

    for (size_t i = 0; i < m_size; i++) {
        temp[i] = m_vector[i];
    }

    delete[] m_vector;
    m_vector = temp;
    m_capacity = newCapacity;
}


//Inserts a new element at the given position.
void Vector::insert(size_t target, const int value) {

    if(target > m_size + 1)
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

}



//swap function - swaps the contents of the current vector with the given vector.
void Vector::swap(Vector& other) {
    std::swap(m_vector, other.m_vector);
    std::swap(m_size, other.m_size);
    std::swap(m_capacity, other.m_capacity);
}


//------------------ operators --------------------
//operator[] Returns the element at the given position.
int& Vector::operator[](size_t index) {

    if(index > m_size-1 || index < 0) throw std::out_of_range("Index out of range");
    return m_vector[index];
}


//operator[] Returns the element at the given position, const version.
const int& Vector::operator[](size_t index) const {

    if(index > m_size-1 || index < 0) throw std::out_of_range("Index out of range");
    return m_vector[index];
}


//operator==
bool Vector::operator==(const Vector& other) const {
    if(m_size != other.size()) return false;

    for (size_t i = 0; i < m_size; ++i) {
        if(m_vector[i] != other.data()[i]) return false;
    }

    return true;
}


//operator!=
bool Vector::operator!=(const Vector& other) const {
    return !(*this == other);
}