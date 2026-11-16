#pragma once
#include "Vector.h"
template <typename T>
class Stack {
    Vector<T>m_Vec;
public:
    void Push(const T&);
    void Push(T&&);
    void Pop();
    T& Top();
    const T& Top() const;
    size_t Size() const;
    bool Empty() const;
};
#include "Stack.tpp"


