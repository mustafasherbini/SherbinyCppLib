#include "../include/Vector.h"
#include <algorithm>

template<typename T>
void Vector<T>::ReAlloc() {

    size_t newCapacity =2 ;

    while (newCapacity<=m_Size)
        newCapacity*=2;

    ReAlloc(newCapacity);
}
template<typename T>
void Vector<T>::ReAlloc(size_t newCapacity) {

    if (newCapacity<m_Size)
        newCapacity=m_Size;

   auto temp_Buffer = newCapacity? (T*)::operator new(newCapacity * sizeof(T))
    : nullptr;

    for (size_t i = 0; i < m_Size; ++i) {
        new (&temp_Buffer[i]) T(std::move(m_Buffer[i]));
        m_Buffer[i].~T();
    }

    ::operator delete(m_Buffer,m_Capacity * sizeof(T));

    m_Buffer=temp_Buffer;
    m_Capacity=newCapacity;
}

template<typename T>
Vector<T>::Vector(size_t size, const T & defaultValue) {
    ReAlloc(size);
    for (int i = 0; i < size; ++i) {
       new (&m_Buffer[i]) T(defaultValue);
    }
    m_Size=size;
}
template<typename T>
Vector<T>::Vector(size_t size) {
    ReAlloc(size);
    for (int i = 0; i < size; ++i) {
        new (&m_Buffer[i]) T();
    }
    m_Size=size;
}

template<typename T>
Vector<T>::Vector(const Vector & other) : m_Size(other.m_Size) , m_Capacity(other.m_Capacity) {

    if (other.Empty() || &other ==this)
        return;

    m_Size=other.m_Size;
    m_Capacity=other.m_Capacity;
    m_Buffer = (T*)::operator new(m_Capacity * sizeof(T));
    for (int i = 0; i < m_Size; ++i) {
        new(&m_Buffer[i]) T(other.m_Buffer[i]);
    }

}

template<typename T>
Vector<T> &Vector<T>::operator=(const Vector & other) {

    if (&other ==this)
        return *this;

    Clear();
    ::operator delete(m_Buffer , m_Capacity* sizeof(T));

    m_Size=other.m_Size;
    m_Capacity=other.m_Capacity;

    if (other.Empty()) {
        m_Buffer = nullptr;
        return *this;
    }

    m_Buffer = (T*)::operator new(other.m_Capacity * sizeof(T));

    for (int i = 0; i < m_Size; ++i) {
        new(&m_Buffer[i]) T(other.m_Buffer[i]);
    }
    return *this;
}
template<typename T>
Vector<T>::Vector(Vector && other) noexcept : m_Size(other.m_Size), m_Capacity(other.m_Capacity), m_Buffer(other.m_Buffer) {

    if (&other == this)
        return;

    other.m_Size=0;
    other.m_Capacity=0;
    other.m_Buffer=nullptr;
}

template<typename T>
Vector<T> &Vector<T>::operator=( Vector && other) noexcept {

    if (&other == &this)
        return *this;

    Clear();
    ::operator delete(m_Buffer , m_Capacity* sizeof(T));

    m_Size= other.m_Size;
    m_Capacity=  other.m_Capacity;
    m_Buffer=  other.m_Buffer;

    other.m_Size=0;
    other.m_Capacity=0;
    other.m_Buffer=nullptr;

    return *this;
}



template<typename T>
Vector<T>::~Vector() {
    Clear();
    ::operator delete(m_Buffer , m_Capacity* sizeof(T));
    m_Buffer=nullptr;
}

template<typename T>
size_t Vector<T>::Size() const {
    return m_Size;
}
template<typename T>
size_t Vector<T>::Capacity() const {
    return m_Capacity;
}

template<typename T>
bool Vector<T>::Empty() const {
    return m_Size==0;
}

template<typename T>
void Vector<T>::Clear() {
    for (size_t i = 0; i < m_Size; ++i) {
        m_Buffer[i].~T();
    }
    m_Size=0;
}

template<typename T>
T&  Vector<T>::Front() {
    return *m_Buffer;
}
template<typename T>
const T&  Vector<T>::Front() const{
    return *m_Buffer;
}
template<typename T>
T&  Vector<T>::Back(){
    return m_Buffer[m_Size-1];
}
template<typename T>
const T&  Vector<T>::Back() const {
    return m_Buffer[m_Size-1];
}
template<typename T>
T*  Vector<T>::begin () {
    return m_Buffer;
}
template<typename T>
const T*  Vector<T>::begin () const {
    return m_Buffer;
}
template<typename T>
T*  Vector<T>::end() {
    return m_Buffer + m_Size ;
}
template<typename T>
const T*  Vector<T>::end() const {
    return m_Buffer + m_Size ;
}

template<typename T>
void Vector<T>::Pop_back() {
    if (!m_Size)
        return;
    m_Size--;
    m_Buffer[m_Size].~T();
}

template<typename T>
void Vector<T>::Push_back(const T & element) {

    if (m_Size >= m_Capacity)
        ReAlloc();

    new (&m_Buffer[m_Size])T(element);
    m_Size++;
}
template<typename T>
void Vector<T>::Push_back( T && element) {

    if (m_Size >= m_Capacity)
        ReAlloc();

    new (&m_Buffer[m_Size])T(std::move(element));
    m_Size++;
}


template<typename T>
T &Vector<T>::operator[](size_t indx) {
    return m_Buffer[indx];
}

template<typename T>
const T &Vector<T>::operator[](size_t indx) const {
    return m_Buffer[indx];
}

template<typename T>
void Vector<T>::Reserve(size_t newCapacity ) {
        ReAlloc(newCapacity);
}


