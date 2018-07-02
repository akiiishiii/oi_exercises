// 1143.cpp
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstdlib>

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
    Number operator+(const Number & n) const;
    Number operator-(const Number & n) const { return *this + -n;}
    Number operator*(const Number & n) const;
    Number operator/(const Number & n) const;
    Number operator%(const Number & n) const;
    Number operator+=(const Number & n);
    Number operator-=(const Number & n);
    Number operator*=(const Number & n);
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

int main(int argc, const char * argv[]) {
    Number a, b;
    std::cin >> a >> b;
    std::cout << a * b << std::endl;
    return 0;
}

int Number::pullout(length i) const {
    if (i < size())
        return isminus ? -1 * num[i] : num[i];
    else
        return 0;
}

Number Number::clear(length i) const {
    Number res = *this;
    if (i < res.size() && i > 0)
    for (length l = 1; res.size() > i; l++)
        res.pop();
    return res;
}

void Number::check() {
    while (!num[0] && size() != 0L) {
        for (int i = 0; i < size(); i++)
            num[i] = num[i + 1];
        pop();
    }
    if (size() == 0) {
        push(0);
        isminus = false;
    }
}

void Number::ac() {
    num.clear();
    isminus = false;
}

Number Number::operator++() {
    Number temp = *this;
    *this += 1;
    return temp;
}

Number Number::operator--() {
    Number temp = *this;
    *this -= 1;
    return temp;
}

Number Number::operator=(const Number & n) {
    num = n.num;
    isminus = n.isminus;
    return *this;
}

Number Number::operator+(const Number & n) const {
    Number sum;
    int x = 0;
    length numm = labs((long)size() - (long)n.size());
    bool big = size() >= n.size();
    length len = big ? size() : n.size();
    sum.num.resize(len + 1);
    if ((!isminus && n.isminus && *this < -n)||(isminus && !n.isminus && -(*this) > n)) {
        return -(-(*this) + -n);
    } else {
        for (length f = len - 1L; f < len; f--) {
            sum.num[f + 1] = pullout(big ? f : f - numm) + n.pullout(big ? f - numm : f) + x;
            x = sum.num[f + 1] >= 0 ? sum.num[f + 1] / 10 : sum.num[f + 1] / 10 - 1;
            sum.num[f + 1] = sum.num[f + 1] >= 0 ? sum.num[f + 1] % 10 : 10 + sum.num[f + 1] % 10;
        }
        sum.num[0] = x;
        sum.check();
        return sum;
    }
}

Number Number::operator-() const {
    Number n = *this;
    n.isminus = !n.isminus;
    return n;
}

Number Number::operator*(const Number & n) const {
    Number product;
    product.isminus = isminus != n.isminus;
    product.num.resize(size() + n.size());
    int x;
    for (length l = size() - 1; l < size(); l--) {
        x = 0;
        for (length m = n.size() - 1L; m < n.size(); m--) {
            product.num[l + m + 1] += num[l] * n.num[m] + x;
            x = product.num[l + m + 1] / 10;
            product.num[l + m + 1] %= 10;
        }
        product.num[l] += x;
    }
    product.check();
    return product;
}

Number Number::operator/(const Number & n) const {
    if (n == 0){
        std::cerr << '\n' << "Invalid, divisor can't be 0!" << '\n';
        return 0;
    } else if (n.abs() <= (*this).abs()) {
        Number ctrl, quo;
        short x = 1;
        quo.num.resize((*this).size());
        for (Number::length l = n.size(); l <= (*this).size(); l++, x = 1) {
            ctrl = clear(l);
            Number tri(n * x);
            while (tri.abs() <= ctrl.abs()) {
                x++;
                tri += n;
            }
            quo[l - 1] = x - 1;
        }
        quo.check();
        quo.isminus = isminus != n.isminus;
        return quo;
    } else {
        return 0;
    }
}

Number Number::operator%(const Number & n) const {
    if (n == 0){
        std::cerr << '\n' << "Invalid, divisor can't be 0!" << '\n';
        return 0;
    } else
        return *this - ((*this / n) * n);
}

Number Number::operator+=(const Number & n) {
    Number res = *this + n;
    *this = res;
    return res;
}

Number Number::operator-=(const Number & n) {
    Number res = *this - n;
    *this = res;
    return res;
}

Number Number::operator*=(const Number & n) {
    Number res = *this * n;
    *this = res;
    return res;
}

bool Number::operator==(const Number & n) const {
    bool b = false;
    if (isminus != n.isminus) {
        if (size() == n.size() && size() == 1L && num[0] == n.num[0] && num[0] == 0)
            return true;
        return false;
    } else if (size() != n.size())
        return false;
    for (length l = 0; l < size(); l++) {
        if (num[l] == n.num[l])
            b = true;
        else {
            b = false;
            break;
        }
    }
    return b;
}

bool Number::operator>(const Number & n) const {
    bool b = false;
    if (*this == n)
        return false;
    else if (isminus && !n.isminus)
        return false;
    else if (!isminus && n.isminus)
        return true;
    if (size() > n.size())
        b = true;
    else if (size() < n.size())
        b = false;
    else
        for (length l = 0; l < size(); l++) {
            if (num[l] > n.num[l]) {
                b = true;
                break;
            } else if (num[l] < n.num[l]) {
                b = false;
                break;
            } else
                continue;
        }
    if (isminus)
        b = !b;
    return b;
}

std::istream & operator>>(std::istream & is, Number & n) {
    std::basic_string<char>::iterator f;
    std::string st;
    short temp;
    bool issign = false;
    is >> st;
    char c = * st.begin();
    if (c == '+' || c == '-') {
        issign = true;
        n.isminus = c == '+' ? false : true;
    }
    for (f = st.begin() + (int)issign ; f != st.end(); f++) {
        if (*f >= '0' && *f <= '9'){
            temp = * f - '0';
            n.push(temp);
        } else if (*f != ',')
            break;
    }
    n.check();
    return is;
}

std::ostream & operator<<(std::ostream & os, const Number & n) {
    if (n.isminus && !(n.size() == 1 && n.num[0] == 0))
        os << '-';
    for (int f = 0; f < n.size(); f++)
        os << n.num[f];
    return os;
}