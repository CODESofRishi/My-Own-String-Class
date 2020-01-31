#ifndef _Mystring_H_
#define _Mystring_H_

class Mystring {
    friend Mystring operator+(const Mystring &lhs, const Mystring& rhs);  // concatenation
    friend bool operator==(const Mystring &lhs, const Mystring &rhs);
    friend bool operator!=(const Mystring &lhs, const Mystring &rhs);
    friend bool operator>(const Mystring &lhs, const Mystring &rhs);
    friend bool operator<(const Mystring &lhs, const Mystring &rhs);

    //overloading streams
    friend std::ostream& operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream& operator>>(std::istream &is, Mystring &rhs);

private:
    char *str;

public:
    Mystring();
    Mystring(const Mystring&);
    Mystring(const Mystring&&);
    Mystring(const char*);
    ~Mystring();

    Mystring& operator=(const Mystring &rhs);  // copy assignment
    Mystring& operator=(const Mystring &&rhs);  // move assignment
    void operator+=(const Mystring &rhs);  // concatenation
    Mystring operator-() const;  // for lowercase conversion
    Mystring operator*(const size_t &rhs_num) const;
    void operator*=(const size_t &rhs_num);


    // TESTING
    void display() const;
};

#endif // _Mystring_H_
