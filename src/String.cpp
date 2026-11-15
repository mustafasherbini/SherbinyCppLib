#include "MyString.h"

#include <cstring>
#include <iostream>
#include <utility>

String::String(const char* string) {

    if (string==nullptr)
        return ;
    m_Size= std::strlen(string);
    m_Buffer= new char[m_Size + 1 ];
    std::memcpy(m_Buffer, string, m_Size);
    m_Buffer[m_Size]='\0';
}


String::~String() {
    delete [] m_Buffer;
}
String::String( const String& other) {

    if (other.m_Buffer == nullptr)
        return;

    m_Size=other.Size() ;
    m_Buffer= new char[m_Size + 1 ];
    std::memcpy(m_Buffer , other.m_Buffer , m_Size + 1 );
}
String& String::operator= (const String& other)  {

    if (this == &other)
        return * this;

    m_Size= 0 ;
    delete [] m_Buffer;
    m_Buffer=nullptr;

    if (other.m_Buffer) {
        m_Size=other.Size() ;
        m_Buffer= new char[m_Size + 1 ];
        std::memcpy(m_Buffer , other.m_Buffer , m_Size + 1 );
    }
    return *this;
}

String::String(String&& other) noexcept :m_Size(other.m_Size),m_Buffer(other.m_Buffer){
    other.m_Buffer=nullptr;
    other.m_Size=0;
}

String& String:: operator= (String&& other) noexcept  {

    if (this == &other)
        return * this;

    delete [] m_Buffer;

    m_Buffer= other.m_Buffer;
    m_Size= other.m_Size;

    other.m_Buffer=nullptr;
    other.m_Size=0;

    return *this;
}

size_t String:: Size() const {
    return m_Size;
}
bool String:: Empty() const {
    return m_Size==0;
}
void String::Print() const {
    if (m_Buffer == nullptr)
        return;
    std::cout << m_Buffer;
}

void String::Clear() {
    delete [] m_Buffer;
    m_Size=0;
    m_Buffer=nullptr;

}

char& String::operator[](size_t indx) {
    return m_Buffer[indx];
}
const char& String::operator[](size_t indx) const {
    return m_Buffer[indx];
}

bool String::operator==(const String & other) const {

    if (m_Size!=other.m_Size)
        return false;
    if (!m_Size)
        return true;
    return !std::strcmp(m_Buffer , other.m_Buffer);
}

bool String::operator!=(const String &other) const {
    return ! operator==(other);
}

String& String::operator+=(const String & other) {

    size_t newSize= m_Size+ other.m_Size;
    char* temp_Buffer = new char[ newSize+ 1];
    temp_Buffer[0]= '\0';

    if (m_Buffer)
        std::strcat(temp_Buffer,m_Buffer);


    if (other.m_Buffer)
        std::strcat(temp_Buffer,other.m_Buffer);

    std::swap(m_Buffer,temp_Buffer);

    m_Size=newSize;

    delete [] temp_Buffer;

    return *this;
}

String String::operator+(const String & other) const {
    String tempString(*this);
    tempString += other;
    return tempString;
    // why not return tempString += other; ? NRVO
    // NRVO stands for Named Return Value Optimization. It is a compiler optimization technique in C++ (a specific type of Copy Elision)
    // that eliminates unnecessary copying or moving when a function returns a named local object by value.
    // I need to learn more about it
}

std::ostream& operator<< ( std::ostream& ostream , const String& other) {
    if (other.m_Buffer!=nullptr)
        ostream<<other.m_Buffer;
    return ostream;
}



