#pragma once
template<typename T>
T &Stack<T>::Top() {
    return m_Vec.Back();
}

template<typename T>
const T &Stack<T>::Top() const {
    return m_Vec.Back();
}

template<typename T>
void Stack<T>::Push(T&& element) {
    m_Vec.Push_back(std::move(element));
}

template<typename T>
void Stack<T>::Push(const T& element) {
     m_Vec.Push_back(element);
}

template<typename T>
void Stack<T>::Pop() {
    m_Vec.Pop_back();
}

template<typename T>
size_t Stack<T>::Size() const {
    return m_Vec.Size();
}

template<typename T>
bool Stack<T>::Empty() const {
    return m_Vec.Empty();
}
