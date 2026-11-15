#pragma once
#include <iostream>

template <typename T>
class Vector {
    size_t m_Size = 0;
    size_t m_Capacity = 0;
    T* m_Buffer = nullptr;

    Vector();
    explicit Vector(size_t);
    Vector(size_t , const T& );
    // rule of 5
    ~Vector();
    Vector( const Vector&);
    Vector& operator= (const Vector&);
    Vector(  Vector&&)noexcept;
    Vector& operator= ( Vector&&)noexcept;


};


