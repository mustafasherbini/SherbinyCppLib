template<typename T>
T &Stack<T>::Top() {
    if (Empty())
        throw std::out_of_range("Stack is empty");
    return m_Vec.Back();
}

template<typename T>
const T &Stack<T>::Top() const {
    if (Empty())
        throw std::out_of_range("Stack is empty");
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
    if (Empty())
        throw std::out_of_range("Stack is empty");
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
