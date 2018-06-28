// numbers.h

#ifndef NUMBERS_H_
#define NUMBERS_H_

#include <sstream>
#include <vector>

class Number {
private:
    typedef unsigned long length;
    std::vector<short> num;
    bool isminus;
    int pullout(length i) const;
    void pop() { num.pop_back();}
    void push(short s) { num.push_back(s);}
    void check();
    Number clear(length i) const;
public:
    Number() { ac();}
    template <typename T>
    Number(const T t) {
        std::stringstream st;
        st << t;
        st >> *this;
    }
    ~Number() { ac();}
    length size() const { return num.size();}
    void ac();
    Number abs() const { return isminus ? -(*this) : *this;}
    Number operator++();
    Number operator--();
    Number operator=(const Number & n);
//  Number operator=(Number & n);
    Number operator+(const Number & n) const;
    Number operator-(const Number & n) const { return *this + -n;}
    Number operator*(const Number & n) const;
//  Number operator*(const unsigned long l) const { return Number(l) * *this;}
    Number operator/(const Number & n) const;
    Number operator%(const Number & n) const;
    Number operator+=(const Number & n);
    Number operator-=(const Number & n);
    Number operator*=(const Number & n);
//  Number operator/=(const Number & n);
//  Number operator%=(const Number & n);
    Number operator-() const;
    short & operator[](const length l) { return num[l];}
    bool operator==(const Number & n) const;
    bool operator>(const Number & n) const;
    bool operator<(const Number & n) const { return *this == n ? false : !(*this > n);}
    bool operator>=(const Number & n) const { return *this == n || * this > n;}
    bool operator<=(const Number & n) const { return *this == n || * this < n;}
    bool operator!=(const Number & n) const { return !(*this == n);}
//  friend functions
    friend std::istream & operator>>(std::istream & is, Number & n);
    friend std::ostream & operator<<(std::ostream & os, const Number & n);
    template <typename T>
    friend Number operator+(const T t, const Number & n) { return n + t;}
    template <typename T>
    friend Number operator-(const T t, const Number & n) { return -(n - t);}
    template <typename T>
    friend Number operator*(const T t, const Number & n) { return n * t;}
    template <typename T>
    friend Number operator/(const T t, const Number & n) { return Number(t) / n;}
    friend Number operator++(Number & n) { return n += 1;}
    friend Number operator--(Number & n) { return n -= 1;}
};
/* For '/' operation. (Used to)
class quotient : public Number {
    friend class Number;
private:
    Number rem;
    bool valid;
public:
    quotient();
    quotient(const Number & n, const Number & r, bool b);
    friend quotient operator/(const Number & n, const Number m);
    friend std::ostream & operator<<(std::ostream & os, const quotient & q);
    Number & virem() { return rem;}
};
*/
#endif /* NUMBERS_H_ */
