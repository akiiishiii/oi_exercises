// number.cpp

#include "numbers.h"
#include <cmath>
#include <cstdlib>
#include <string>
#include <iostream>

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
/*
Number Number::operator=(Number &n) {
    num = n.num;
    minus = n.minus;
    return *this;
}
*/
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
/*
Number Number::operator*(const long long l) const {
    Number n(l);
    return *this * n;
}
*/
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
/*
quotient::quotient() : Number() {
    rem.ac();
    valid = true;
}

quotient::quotient(const Number & n, const Number & r, bool b) : Number(n) {
    rem = r;
    valid = b;
}

quotient operator/(const Number & n, const Number & m) {
    if (m == 0){
        return quotient(0, 0, false);
    } else {
        Number ctrl, calc = n, tri;
        quotient quo;
        short x = 0;
        for (Number::length l = m.size(); l <= m.size(); l++) {
            ctrl = n.clear(l);
            while (tri <= ctrl) {
                tri = m * x;
                quo[l]++;
                x++;
            }
            calc -= m * quo[l];
        }
    quo.virem() = calc;
    return quo;
    }
}

std::ostream & operator<<(std::ostream & os, const quotient & q) {
    if (q.valid) {
        Number n = q;
        os << n << "……" << q.rem;
    } else
        os << '\n' << "Invalid, divisor can't be 0!" << '\n';
    return os;
}
*/
