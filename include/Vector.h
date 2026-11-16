#pragma once
#include <iostream>
#include <utility>
#include <new>
template <typename T>
class Vector {

    size_t m_Size = 0;
    size_t m_Capacity = 0;
    T* m_Buffer = nullptr;
    void ReAlloc(size_t newCapacity);
    void ReAlloc();

public:
    Vector() = default;
    explicit Vector(size_t);
    Vector(size_t , const T& );
    // rule of 5
    ~Vector();
    Vector( const Vector&);
    Vector& operator= (const Vector&);
    Vector( Vector&&)noexcept;
    Vector& operator= ( Vector&&)noexcept;

    size_t Size() const;
    size_t Capacity() const;
    bool Empty() const;

    void Push_back(const T&);
    void Push_back( T&&);

    void Pop_back();
    void Clear();
    void Reserve(size_t);

    T& Front();
    const T& Front() const ;

    T& Back();
    const T& Back() const;

    T* begin ();
    const T* begin ()const ;

    T* end();
    const T* end() const;

    T& operator[](size_t );
    const T& operator[](size_t ) const;

};
#include "Vector.tpp"

