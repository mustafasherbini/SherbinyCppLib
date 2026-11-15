#pragma once
#include <iostream>

template <typename T>
class Vector {


    size_t m_Size = 0;
    size_t m_Capacity = 0;
    T* m_Buffer = nullptr;
    void ReAlloc();
public:
    Vector();
    explicit Vector(size_t);
    Vector(size_t , const T& );
    // rule of 5
    ~Vector();
    Vector( const Vector&);
    Vector& operator= (const Vector&);
    Vector(  Vector&&)noexcept;
    Vector& operator= ( Vector&&)noexcept;

    size_t Size() const;
    size_t Capacity() const;
    bool Empty() const;

    void Push_back(const T&);
    void Push_back( T&&);

    void Pop_back();
    void Clear();
    void Reserve(size_t newCapacity);

    T& Front();
    const T& Front() const ;

    T& Back();
    const T& Back() const;

    T* Begin ();
    const T* Begin ()const ;

    T* End();
    const T* End() const;

    T& operator[](size_t inx);
    const T& operator[](size_t inx) const;



};


