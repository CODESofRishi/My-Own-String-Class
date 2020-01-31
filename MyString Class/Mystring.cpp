#include <iostream>
#include <cstring>
#include "Mystring.h"

Mystring::Mystring()
    :str {nullptr} {
        // TEST
        std::cout<<"Zero-args constructor called"<<std::endl;
        str = new char[1];
        *str = '\0';
    }

Mystring::Mystring(const char *temp)
    :str {nullptr} {
        // TEST
        std::cout<<"Character-args constructor called"<<std::endl;
        str = new char[std::strlen(temp) + 1];
        std::strcpy(str, temp);
    }

Mystring::Mystring(const Mystring& rhs)
    :str {nullptr} {
        // TEST
        std::cout<<"Copy constructor"<<std::endl;
        delete [] str;
        str = new char[std::strlen(rhs.str) + 1];
        std::strcpy(str, rhs.str);
    }

Mystring::Mystring(const Mystring &&rhs)
    :str {nullptr} {
        // TEST
        std::cout<<"Move constructor"<<std::endl;
        delete [] str;
        str = new char[std::strlen(rhs.str) + 1];
        std::strcpy(str, rhs.str);
    }

Mystring::~Mystring() {
    delete [] str;
}

// =================================================

// copy assignment
Mystring& Mystring::operator=(const Mystring &rhs) {
    if (this == &rhs) return *this;
    delete [] str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);
    return *this;
}

// move assignment
Mystring& Mystring::operator=(const Mystring &&rhs) {
    if (this == &rhs)
        return *this;
    delete [] str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);
    return *this;
}

bool operator==(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str, rhs.str) == 0);
}

bool operator!=(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str, rhs.str) != 0);
}

bool operator>(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str, rhs.str) == 1);
}

bool operator<(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str, rhs.str) == -1);
}

Mystring operator+(const Mystring &lhs, const Mystring &rhs) {
    char *buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

void Mystring::operator+=(const Mystring &rhs) {
    Mystring temp {operator+(*this, rhs)};
    delete [] str;
    str = new char[std::strlen(temp.str) + 1];
    std::strcpy(str, temp.str);
}

Mystring Mystring::operator-() const {
    char *buff = new char[std::strlen(str) + 1];
    for (size_t i {}; i < std::strlen(str)+1; ++i)
        buff[i] = tolower(str[i]);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

Mystring Mystring::operator*(const size_t &rhs_num) const {
    if (rhs_num < 1) {
        std::cout<<"INVALID CONCATENATION ! (number of times to be concatenated should be at least 1)"<<std::endl;
        return *this;
    }
    char *buff = new char[rhs_num*std::strlen(str) + 1];
    std::strcpy(buff, str);
    for (size_t i {rhs_num-1}; i; --i) {
        std::strcat(buff, str);
    }
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

void Mystring::operator*=(const size_t &rhs_num) {
    Mystring temp {operator*(rhs_num)};
    delete [] str;
    str = new char[std::strlen(temp.str) + 1];
    std::strcpy(str, temp.str);
}

// overloading streams
std::ostream& operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

std::istream& operator>>(std::istream &is, Mystring &rhs) {
    char *buff = new char[1000];
    is >> buff;
    delete [] rhs.str;
    rhs.str = new char[std::strlen(buff) + 1];
    std::strcpy(rhs.str, buff);
    delete [] buff;
    return is;
}

// =================================================

// TESTING
void Mystring::display() const {
    std::cout<<"str: "<<str<<" str-length: "<<std::strlen(str)<<std::endl;
}
