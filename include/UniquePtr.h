#pragma once

template<typename T>
class UniquePtr {

    T* m_Pointer = nullptr;
public:
    UniquePtr()noexcept = default;
    explicit UniquePtr(T*)noexcept;

    UniquePtr(const UniquePtr&)=delete;
    UniquePtr& operator=(const UniquePtr&)=delete;

    UniquePtr( UniquePtr&&)noexcept;
    UniquePtr& operator=( UniquePtr&&)noexcept;

    ~UniquePtr();
    T* Get() const noexcept;
    T* Release()noexcept;
    void Reset(T* ptr = nullptr) noexcept;
    T& operator*() const noexcept;
    T* operator->() const noexcept;
    explicit operator bool() const noexcept;
};

#include "UniquePtr.tpp"
