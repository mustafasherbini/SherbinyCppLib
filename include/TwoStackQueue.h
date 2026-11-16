#pragma once
#include "Stack.h"
#include <stdexcept>
#include <utility>
#include <cstddef>
template <typename T>
class TwoStackQueue {
    Stack<T> m_In;
    Stack<T> m_Out;
    void Shift();

public:
    void Push(const T&);
    void Push(T&&);
    void Pop();
    T& Front();
    size_t Size() const;
    bool Empty() const;
};

#include "TwoStackQueue.tpp"
