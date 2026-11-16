

template<typename T>
void TwoStackQueue<T>::Shift() {
while (!m_In.Empty()) {
    m_Out.Push(std::move(m_In.Top()));
    m_In.Pop();
}
}

template<typename T>
T &TwoStackQueue<T>::Front() {
    if (Empty())
        throw std::out_of_range("Queue is empty");
    if (m_Out.Empty()) Shift();
    return m_Out.Top();
}

template<typename T>
void TwoStackQueue<T>::Push(const T & element) {
     m_In.Push(element);
}

template<typename T>
void TwoStackQueue<T>::Push(T && element) {
    m_In.Push(std::move(element));
}

template<typename T>
void TwoStackQueue<T>::Pop() {
    if (Empty())
        throw std::out_of_range("Queue is empty");
    if (m_Out.Empty()) Shift();
    m_Out.Pop();
}

template<typename T>
bool TwoStackQueue<T>::Empty() const {
return Size()==0;
}

template<typename T>
size_t TwoStackQueue<T>::Size() const {
return m_In.Size() + m_Out.Size();
}
