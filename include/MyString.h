#pragma once

#include <iostream>

class String {
    size_t m_Size = 0;
    char* m_Buffer = nullptr;
public:
    String() =default;
    String(const char*);

    // rule of 5
    ~String() ;
    String( const String& );
    String& operator= (const String&);
    String(String&&) noexcept;
    String& operator= (String&&) noexcept;

    size_t Size() const;
    bool Empty() const;
    void Print() const ;
    void Clear();
    char& operator[](size_t );
    const char& operator[](size_t) const;
    bool operator==(const String &) const;
    bool operator!=(const String &) const;
    String& operator+=(const String &);

    String operator+(const String &) const;

    friend std::ostream& operator<< ( std::ostream&  , const String&);

};


