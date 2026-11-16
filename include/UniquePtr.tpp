#pragma once

template<typename T>
UniquePtr<T>::UniquePtr(T* newRowPointer) noexcept : m_Pointer(newRowPointer){
}

template<typename T>
UniquePtr<T>::UniquePtr(UniquePtr && other) noexcept : m_Pointer(other.m_Pointer){
        other.m_Pointer=nullptr;
}

template<typename T>
UniquePtr<T>::~UniquePtr() {
    delete m_Pointer;
    m_Pointer=nullptr;
}

template<typename T>
T *UniquePtr<T>::Get() const noexcept {
return m_Pointer;
}

template<typename T>
T *UniquePtr<T>::Release() noexcept {
 auto temp_Pinter = m_Pointer;
    m_Pointer=nullptr;
    return temp_Pinter;
}

template<typename T>
void UniquePtr<T>::Reset(T *ptr) noexcept {
    if (ptr==m_Pointer)
        return;
    delete m_Pointer;
    m_Pointer = ptr;
}

template<typename T>
UniquePtr<T>::operator bool() const noexcept {
return m_Pointer!=nullptr;
}

template<typename T>
T &UniquePtr<T>::operator*() const noexcept {
    return *m_Pointer;
}

template<typename T>
T *UniquePtr<T>::operator->() const noexcept {
return m_Pointer;
}

template<typename T>
UniquePtr<T> &UniquePtr<T>::operator=(UniquePtr && other) noexcept {
    if (this == &other)
        return *this;

    delete m_Pointer;
    this->m_Pointer=other.m_Pointer;
    other.m_Pointer=nullptr;
    return *this;
}
